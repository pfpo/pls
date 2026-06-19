import pandas as pd


def compare_csvs(file1_path, file2_path, match_col, compare_col):
    try:
        df1 = pd.read_csv(file1_path)
        df2 = pd.read_csv(file2_path)

        for df, name in [(df1, "File 1"), (df2, "File 2")]:
            if match_col not in df.columns:
                raise ValueError(
                    f"Error: Column '{match_col}' not found in {name}."
                )
            if compare_col not in df.columns:
                raise ValueError(
                    f"Error: Column '{compare_col}' not found in {name}."
                )

        df1_sub = df1[[match_col, compare_col]].dropna(subset=[match_col])
        df2_sub = df2[[match_col, compare_col]].dropna(subset=[match_col])

        merged = pd.merge(
            df1_sub,
            df2_sub,
            on=match_col,
            suffixes=("_file1", "_file2"),
            how="outer",
        )

        both_exist = merged[
            merged[f"{compare_col}_file1"].notna()
            & merged[f"{compare_col}_file2"].notna()
        ]
        mismatches = both_exist[
            both_exist[f"{compare_col}_file1"]
            != both_exist[f"{compare_col}_file2"]
        ]

        missing_in_file2 = merged[merged[f"{compare_col}_file2"].isna()]
        missing_in_file1 = merged[merged[f"{compare_col}_file1"].isna()]

        print("=== COMPARISON REPORT ===")
        print(f"Total rows evaluated: {len(merged)}\n")

        print(f"--- Mismatches found ({len(mismatches)}) ---")
        if not mismatches.empty:
            print(mismatches.to_string(index=False))
        else:
            print("None! All matching rows have identical values.")

        print(f"\n--- Missing in File 2 ({len(missing_in_file2)}) ---")
        if not missing_in_file2.empty:
            print(missing_in_file2[[match_col, f"{compare_col}_file1"]])

        print(f"\n--- Missing in File 1 ({len(missing_in_file1)}) ---")
        if not missing_in_file1.empty:
            print(missing_in_file1[[match_col, f"{compare_col}_file2"]])

    except FileNotFoundError as e:
        print(f"File Error: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")


FILE1 = "benchmark_results_MT_recurso/benchmark_results.csv"
FILE2 = "benchmark_results_MT_recurso_old/benchmark_results.csv"
MATCH_COLUMN = "file"
COMPARE_COLUMN = "explicit_unification"

compare_csvs(FILE1, FILE2, MATCH_COLUMN, COMPARE_COLUMN)