### helper script to delete files with haskell exercises
### student_answers_MT-recurso prolog files are 4.X, haskell are 1.X 
### haskell files and prolog files have all .pl extension, but haskell files starts with "1." in their name, while prolog files starts with "4." in their name
### this will delete all haskell files, but not prolog files
### file structure is student_answers_MT-recurso/student_id/X.X.pl

import os
def delete_haskell_files(root_dir):
    for student_id in os.listdir(root_dir):
        student_dir = os.path.join(root_dir, student_id)
        if os.path.isdir(student_dir):
            for filename in os.listdir(student_dir):
                if filename.startswith("1.") or filename.startswith("2."):
                    file_path = os.path.join(student_dir, filename)
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")

if __name__ == "__main__":
    root_directory = "student_answers_MT-recurso"
    delete_haskell_files(root_directory)