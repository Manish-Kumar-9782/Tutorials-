import subprocess


def show_git_diff(files_or_dirs):
    try:
        # Construct the git diff command
        command = ['git', 'diff'] + files_or_dirs

        # Run the git diff command
        result = subprocess.run(command, capture_output=True, text=True)

        # Check if the command was successful
        if result.returncode == 0:
            print("Difference with the last commit:")
            print(result.stdout)
            file = open("diff.txt", 'w')
            file.write(result.stdout)
            file.close()
        else:
            print(f"Error: {result.stderr}")
    except Exception as e:
        print(f"An error occurred: {e}")


# Example usage
if __name__ == "__main__":
    # Compare specific files and directories
    files_or_dirs = ["."]
    show_git_diff(files_or_dirs)
