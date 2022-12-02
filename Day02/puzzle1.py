if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


"""
    "A": "Rock",    
    "B": "Paper",    
    "C": "Scissors",
    
    "X": "Rock",
    "Y": "Paper",
    "T": "Scissors",
    
    "Rock": 1,
    "Paper": 2,
    "Scissors": 3,

    "lost": 0,
    "draw": 3,
    "win": 6
"""


convert_dist: dict = {
    "X": "A",
    "Y": "B",
    "Z": "C"
}

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

        elf_choise, my_choise = line.split(" ")
        my_choise = convert_dist[my_choise]

        if my_choise == elf_choise:
            score += DRAW + values[my_choise]
            continue

        match elf_choise:
            case "A":
                if my_choise == "B":
                    score += WIN

            case "B":
                if my_choise == "C":
                    score += WIN

            case "C":
                if my_choise == "A":
                    score += WIN

        score += values[my_choise]

print(score)
