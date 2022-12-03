if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


def find_common_char(str1: str, str2: str) -> str:
    for c in str1:
        if str2.find(c) != -1:
            return c


def priority_from_char(c: str) -> int:
    if c.islower():
        return ord(c) - 96 #96 being ASCII value for char before 'a'
    
    return ord(c) - 65 + 27



sum_of_priorities = 0

with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        if line[-1] == '\n':
            line = line[:-1]
    
        compartment1 = line[:len(line)//2]
        compartment2 = line[len(line)//2:]
        
        char = find_common_char(compartment1, compartment2)
        sum_of_priorities += priority_from_char(char)

print(sum_of_priorities)