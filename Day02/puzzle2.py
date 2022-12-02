if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


"""
    "A": "Rock",    
    "B": "Paper",    
    "C": "Scissors",
        
    "X": "lose",
    "Y": "draw",
    "T": "win",
    
    "Rock": 1,
    "Paper": 2,
    "Scissors": 3,

    "lost": 0,
    "draw": 3,
    "win": 6
"""

LOSE: int = 0
DRAW: int = 3
WIN:  int = 6

values: dict = {
    "A": 1,
    "B": 2,
    "C": 3
}


score: int = 0

with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        if line[-1] == "\n":
            line = line[:-1]
        
        elf_choise, needs_to_end  = line.split(" ")
        
        match needs_to_end:
            case "X": #lose
                score += LOSE

                value = values[elf_choise]
                score += (((value-1) + 2) % 3) + 1
            
            case "Y": #draw
               score += DRAW
               score += values[elf_choise]
            
            case "Z": #win
                score += WIN

                value = values[elf_choise]
                score += (value % 3) + 1

print(score)
        
        
        

