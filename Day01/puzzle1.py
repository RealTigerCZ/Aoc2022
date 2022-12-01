if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"
    
# LAZY implementation
    
calories_list: list[list] = []


with open(INPUT_FILE, "r") as f:
    calories: list[int] = []
    for line in f.readlines():
        if line == "\n":
            calories_list.append(calories)
            calories = []
        else:
            calories.append(int(line))
    calories_list.append(calories)

calories_list_int: list[int] = []

for cal_list in calories_list:
    n = 0
    for cal in cal_list:
        n += cal
    calories_list_int.append(n)
    
print(max(calories_list_int))
    