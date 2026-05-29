#!/usr/bin/env python3
"""
Prolog Language Server Benchmarking Suite

Benchmark the analysis pipeline on a collection of Prolog files.
Measures: execution time, peak memory, and error counts per pass.

Usage:
    python -m pls.benchmark --input-dir ./student_answers_MT-recurso --verbose
"""

import argparse
import json
import csv
import sys
from pathlib import Path
from typing import List, Dict
from collections import defaultdict
import statistics

from pls.benchmark_runner import BenchmarkAnalyzer


def discover_prolog_files(input_dir: Path) -> List[Path]:
    """Recursively discover all .pl files in a directory."""
    if not input_dir.exists():
        print(f"Error: Input directory does not exist: {input_dir}", file=sys.stderr)
        sys.exit(1)
    
    prolog_files = [f for f in input_dir.rglob('*.pl') if f.is_file()]
    return sorted(prolog_files)


def run_benchmark(
    input_dir: Path,
    output_dir: Path,
    verbose: bool = False,
    disable_passes: str = None,
) -> None:
    """Run benchmark on all Prolog files in input directory."""
    
    # Discover files
    prolog_files = discover_prolog_files(input_dir)
    print(f"Found {len(prolog_files)} Prolog files", file=sys.stderr)
    
    if len(prolog_files) == 0:
        print("Warning: No .pl files found", file=sys.stderr)
        return
    
    # Create output directory
    output_dir.mkdir(parents=True, exist_ok=True)
    
    # Initialize analyzer
    analyzer = BenchmarkAnalyzer()
    
    # Run analysis on all files
    results = []
    errors_by_pass_aggregate = defaultdict(int)
    timing_data = []
    memory_data = []
    file_errors = []
    
    print(f"Starting analysis of {len(prolog_files)} files...", file=sys.stderr)
    
    for idx, file_path in enumerate(prolog_files, 1):
        if verbose:
            print(f"[{idx}/{len(prolog_files)}] Analyzing {file_path.relative_to(input_dir)}...", 
                  file=sys.stderr, end='', flush=True)
        
        result = analyzer.analyze_file(str(file_path))
        results.append(result)
        
        # Aggregate metrics
        if result['exception'] is None:
            timing_data.append(result['time_ms'])
            memory_data.append(result['memory_mb'])
            file_errors.append((str(file_path.relative_to(input_dir)), result['total_errors']))
            
            # Aggregate error counts
            for pass_name, count in result['errors_by_pass'].items():
                errors_by_pass_aggregate[pass_name] += count
        
        if verbose:
            if result['exception']:
                print(f" ERROR: {result['exception']}", file=sys.stderr)
            else:
                print(f" {result['total_errors']} errors, {result['time_ms']:.2f}ms", 
                      file=sys.stderr)
    
    # Generate reports
    print(f"Generating reports...", file=sys.stderr)
    
    # 1. CSV report
    csv_path = output_dir / "benchmark_results.csv"
    _write_csv_report(csv_path, results)
    print(f"✓ CSV report: {csv_path}", file=sys.stderr)
    
    # 2. JSON summary
    json_path = output_dir / "benchmark_summary.json"
    summary = _generate_summary(
        results,
        timing_data,
        memory_data,
        file_errors,
        errors_by_pass_aggregate,
    )
    _write_json_summary(json_path, summary)
    print(f"✓ JSON summary: {json_path}", file=sys.stderr)
    
    # 3. Print summary to stdout
    print("\n" + "=" * 70, file=sys.stderr)
    print("BENCHMARK SUMMARY", file=sys.stderr)
    print("=" * 70, file=sys.stderr)
    _print_summary_to_stdout(summary)
    print("=" * 70, file=sys.stderr)


def _write_csv_report(csv_path: Path, results: List[Dict]) -> None:
    """Write detailed results to CSV file."""
    if not results:
        return
    
    # Collect all pass names
    all_passes = set()
    for result in results:
        all_passes.update(result['errors_by_pass'].keys())
    all_passes = sorted(all_passes)
    
    # CSV columns: file, time_ms, memory_mb, [per-pass errors], total_errors, exception
    columns = ['file', 'time_ms', 'memory_mb'] + all_passes + ['total_errors', 'exception']
    
    with open(csv_path, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=columns)
        writer.writeheader()
        
        for result in results:
            row = {
                'file': result['file'],
                'time_ms': f"{result['time_ms']:.3f}",
                'memory_mb': f"{result['memory_mb']:.3f}",
                'total_errors': result['total_errors'],
                'exception': result['exception'] or '',
            }
            
            for pass_name in all_passes:
                row[pass_name] = result['errors_by_pass'].get(pass_name, 0)
            
            writer.writerow(row)


def _generate_summary(
    results: List[Dict],
    timing_data: List[float],
    memory_data: List[float],
    file_errors: List[tuple],
    errors_by_pass_aggregate: Dict[str, int],
) -> Dict:
    """Generate comprehensive summary statistics."""
    
    successful_runs = [r for r in results if r['exception'] is None]
    failed_runs = [r for r in results if r['exception'] is not None]
    
    # Sort file_errors by error count (descending)
    top_error_files = sorted(file_errors, key=lambda x: x[1], reverse=True)[:10]
    
    # Timing statistics
    timing_stats = {}
    if timing_data:
        timing_stats = {
            'total_ms': sum(timing_data),
            'avg_ms': statistics.mean(timing_data),
            'median_ms': statistics.median(timing_data),
            'min_ms': min(timing_data),
            'max_ms': max(timing_data),
            'stddev_ms': statistics.stdev(timing_data) if len(timing_data) > 1 else 0,
        }
    
    # Memory statistics
    memory_stats = {}
    if memory_data:
        memory_stats = {
            'total_mb': sum(memory_data),
            'avg_mb': statistics.mean(memory_data),
            'median_mb': statistics.median(memory_data),
            'min_mb': min(memory_data),
            'max_mb': max(memory_data),
            'stddev_mb': statistics.stdev(memory_data) if len(memory_data) > 1 else 0,
        }
    
    summary = {
        'total_files': len(results),
        'successful_runs': len(successful_runs),
        'failed_runs': len(failed_runs),
        'timing': timing_stats,
        'memory': memory_stats,
        'errors': {
            'total': sum(errors_by_pass_aggregate.values()),
            'by_pass': dict(sorted(errors_by_pass_aggregate.items())),
        },
        'top_error_files': [
            {'file': f, 'error_count': e} for f, e in top_error_files
        ],
        'failed_files': [
            {'file': r['file'], 'exception': r['exception']} for r in failed_runs
        ] if failed_runs else [],
    }
    
    return summary


def _write_json_summary(json_path: Path, summary: Dict) -> None:
    """Write summary to JSON file."""
    with open(json_path, 'w') as f:
        json.dump(summary, f, indent=2)


def _print_summary_to_stdout(summary: Dict) -> None:
    """Print summary statistics to stdout."""
    print(f"\nTotal Files:       {summary['total_files']}", file=sys.stderr)
    print(f"Successful Runs:   {summary['successful_runs']}", file=sys.stderr)
    print(f"Failed Runs:       {summary['failed_runs']}", file=sys.stderr)
    
    if summary['timing']:
        t = summary['timing']
        print(f"\nTiming Statistics (ms):", file=sys.stderr)
        print(f"  Total:   {t['total_ms']:>10.2f}", file=sys.stderr)
        print(f"  Average: {t['avg_ms']:>10.3f}", file=sys.stderr)
        print(f"  Median:  {t['median_ms']:>10.3f}", file=sys.stderr)
        print(f"  Min:     {t['min_ms']:>10.3f}", file=sys.stderr)
        print(f"  Max:     {t['max_ms']:>10.3f}", file=sys.stderr)
        print(f"  Stddev:  {t['stddev_ms']:>10.3f}", file=sys.stderr)
    
    if summary['memory']:
        m = summary['memory']
        print(f"\nMemory Statistics (MB):", file=sys.stderr)
        print(f"  Total:   {m['total_mb']:>10.3f}", file=sys.stderr)
        print(f"  Average: {m['avg_mb']:>10.3f}", file=sys.stderr)
        print(f"  Median:  {m['median_mb']:>10.3f}", file=sys.stderr)
        print(f"  Min:     {m['min_mb']:>10.3f}", file=sys.stderr)
        print(f"  Max:     {m['max_mb']:>10.3f}", file=sys.stderr)
        print(f"  Stddev:  {m['stddev_mb']:>10.3f}", file=sys.stderr)
    
    if summary['errors']:
        e = summary['errors']
        print(f"\nError Statistics:", file=sys.stderr)
        print(f"  Total Errors: {e['total']}", file=sys.stderr)
        if e['by_pass']:
            print(f"  By Pass:", file=sys.stderr)
            for pass_name, count in sorted(e['by_pass'].items(), key=lambda x: x[1], reverse=True):
                print(f"    {pass_name:.<40} {count:>6}", file=sys.stderr)
    
    if summary['top_error_files']:
        print(f"\nTop Files by Error Count:", file=sys.stderr)
        for idx, item in enumerate(summary['top_error_files'], 1):
            print(f"  {idx:2}. {item['file']:.<50} {item['error_count']:>4} errors", 
                  file=sys.stderr)


def main():
    parser = argparse.ArgumentParser(
        description="Benchmark Prolog Language Server analysis pipeline",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python -m pls.benchmark --input-dir ./student_answers_MT-recurso --verbose
  python -m pls.benchmark --input-dir ./prolog_examples --output-dir ./results
        """
    )
    
    parser.add_argument(
        '--input-dir',
        type=Path,
        default=Path('./student_answers_MT-recurso'),
        help='Directory containing Prolog files (default: ./student_answers_MT-recurso)',
    )
    
    parser.add_argument(
        '--output-dir',
        type=Path,
        default=Path('./benchmark_results'),
        help='Directory for output reports (default: ./benchmark_results)',
    )
    
    parser.add_argument(
        '--verbose',
        action='store_true',
        help='Print detailed progress for each file',
    )
    
    parser.add_argument(
        '--disable-passes',
        type=str,
        help='Comma-separated list of passes to disable',
    )
    
    args = parser.parse_args()
    
    try:
        run_benchmark(
            args.input_dir,
            args.output_dir,
            verbose=args.verbose,
            disable_passes=args.disable_passes,
        )
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == '__main__':
    main()
