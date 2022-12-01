from os import mkdir 
from os.path import exists
from sys import argv, stderr
from shutil import copyfile


if (len(argv)) == 1:
    print("No arguments passed", file=stderr)
    exit(1)
    
if (len(argv) > 2):
    print("Too many arguments passed", file=stderr)
    exit(1)

try:
    day = int(argv[1])
except ValueError:
    print(f"Argument '{argv[1]}' is not a valid number.", file=stderr)
    exit(1)

if day < 1 or day > 25:
    print("Argument can be only between 1 and 25 including.", file=stderr)
    exit(1)

URL = f"https://adventofcode.com/2022/day/{day}/input"
day = "Day%02d" % day

if exists(day):
    print(f"Day '{day}' already exists", file=stderr)
    exit(1)


print(f"Making folder '{day}'.")
mkdir(day)

print("Copying template files.")
copyfile("./Template/template.py", f"./{day}/puzzle1.py")
copyfile("./Template/template.py", f"./{day}/puzzle2.py")
copyfile("./Template/template.c", f"./{day}/puzzle1.c")
copyfile("./Template/template.c", f"./{day}/puzzle2.c")
copyfile("./Template/Makefile", f"./{day}/Makefile")

print("Creating input files.")
with open(f"./{day}/input.txt", "x") as f:
    f.write(f"Inputs differ by user, input can be found at: {URL}")

f = open(f"./{day}/input_simple.txt", "x")
f.close()
