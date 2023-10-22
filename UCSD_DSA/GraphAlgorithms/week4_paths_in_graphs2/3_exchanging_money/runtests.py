import os

# Specify the directory path where you want to search for files
directory_path = '/home/panirpal/workspace/Learning/Courses/UCSD_DSA/GraphAlgorithms/week4_paths_in_graphs2/3_exchanging_money'

# List all files in the directory
files = os.listdir(directory_path)

# Filter files that start with "input"
input_files = [file for file in files if file.startswith("input")]

# Print the names of the input files

os.system("g++ shortest_paths.cpp -o shortest_path")
print("program compiled successfully!\n")

for file in input_files:
    print("for test case : ",file)
    os.system("./shortest_path < "+file)
    print("\n\n")


