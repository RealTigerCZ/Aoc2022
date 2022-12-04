if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        if line[-1] == '\n':
            line = line[:-1]
