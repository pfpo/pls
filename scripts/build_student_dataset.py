import argparse
from pathlib import Path
from typing import List


def collect_student_files(student_dir: Path) -> List[Path]:
    return sorted(student_dir.glob('*.pl'), key=lambda p: p.name)


def build_shared_definitions() -> str:
    return (
        "%% Auto-generated shared dataset predicates for consistency\n"
        "book(_, _, _, _, _) :-\n"
        "    false.\n\n"
        "author(_, _, _, _) :-\n"
        "    false.\n\n"
        "read_book(_, _) :-\n"
        "    false.\n\n"
        "gives_gift_to(_, _, _) :-\n"
        "    false.\n\n"
        "rule(_, _) :-\n"
        "    false.\n\n"
    )


def build_dataset(source_dir: Path, target_dir: Path) -> None:
    if not source_dir.exists() or not source_dir.is_dir():
        raise ValueError(f'Source directory does not exist: {source_dir}')

    target_dir.mkdir(parents=True, exist_ok=True)

    shared_definitions = build_shared_definitions()

    for student_dir in sorted(source_dir.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else p.name):
        if not student_dir.is_dir():
            continue
        student_output_dir = target_dir / student_dir.name
        student_output_dir.mkdir(parents=True, exist_ok=True)

        student_code_lines: List[str] = [shared_definitions]
        student_files = collect_student_files(student_dir)

        common_path = student_output_dir / 'common.pl'
        common_path.write_text('\n'.join(student_code_lines), encoding='utf-8')

        for file_path in student_files:
            current_code = file_path.read_text(encoding='utf-8')

            output_lines = []
            output_lines.append('%% Automatically generated exercise file for student ' + student_dir.name)
            output_lines.append('%% Includes a shared common.pl with prior definitions and shared predicates')
            output_lines.append('')
            output_lines.append(":- consult('common.pl').")
            output_lines.append('')
            output_lines.append('%% Current exercise code:')
            output_lines.append(current_code)

            output_path = student_output_dir / file_path.name
            output_path.write_text('\n'.join(output_lines), encoding='utf-8')

            student_code_lines.append('% --- Begin code from: ' + file_path.name)
            student_code_lines.extend(current_code.splitlines())
            student_code_lines.append('% --- End code from: ' + file_path.name)
            student_code_lines.append('')

            common_path.write_text('\n'.join(student_code_lines), encoding='utf-8')


def main() -> None:
    parser = argparse.ArgumentParser(description='Rebuild student dataset with a shared common.pl and consult directives.')
    parser.add_argument('--source', type=Path, default=Path('student_answers_MT2_2024_old'), help='Source dataset directory')
    parser.add_argument('--target', type=Path, default=Path('student_answers_MT2_2024'), help='Target fixed dataset directory')
    args = parser.parse_args()

    build_dataset(args.source, args.target)
    print(f'Built fixed dataset at: {args.target}')


if __name__ == '__main__':
    main()
