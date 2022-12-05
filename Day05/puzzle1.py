if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


moves: list[tuple[int, int, int]] = []
stacks: list[list[str]] = []


def parse_cargo(line: str):
    stack_idx:int = 0
    ch_idx:int = 0
    
    while ch_idx < len(line):
        if line[ch_idx] == "[":
            stacks[stack_idx].append(line[ch_idx + 1]) 
        
        ch_idx += 4
        stack_idx += 1
    


def make_move(move):
    for i in range(move[0]):
        stacks[move[2]].append(stacks[move[1]].pop())



with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        if line == "\n":
            continue
        
        if line[-1] == '\n':
            line = line[:-1]
        
        if line.startswith("move"):
            line = line.split(" ")
            move = (int(line[1]), int(line[3]) - 1, int(line[5]) - 1)
            moves.append(move)
            
        elif line.startswith(" 1"):
            continue
        
        elif line.startswith("[") or line.startswith("    "):
            if len(stacks) == 0:
                stacks = [[] for _ in range(len(line)//4 + 1)]
            
            parse_cargo(line)
            
        else:
            print(f"Can not parse line: '{line}'")

stacks = [list(reversed(stack)) for stack in stacks]         

for move in moves:
    make_move(move)
    
print("".join([stack.pop() for stack in stacks]))
        
