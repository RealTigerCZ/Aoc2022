if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"

def find_common_char(str1: str, str2: str, str3: str) -> str:
    return set.intersection(set(str1), set(str2), set(str3)).pop()


def priority_from_char(c: str) -> int:
    if c.islower():
        return ord(c) - 96  # 96 being ASCII value for char before 'a'

    return ord(c) - 65 + 27

sum_of_priorities = 0

with open(INPUT_FILE, "r") as file:
    lines = file.readlines()
    lines = [l.strip('\n\r') for l in lines]
    
    for i in range(0, len(lines), 3):
        line1 = lines[i]
        line2 = lines[i + 1]
        line3 = lines[i + 2]
        
        char = find_common_char(line1, line2, line3)
        sum_of_priorities += priority_from_char(char)
        
print(sum_of_priorities)
    
    
