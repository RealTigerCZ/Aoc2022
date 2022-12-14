if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"

calories: list[int] = []

with open(INPUT_FILE, "r") as f:
    n = 0
    
    for line in f.readlines():
        if line == "\n":
            calories.append(n)
            n = 0
        else:
            n += int(line)
    
    calories.append(n)

calories = sorted(calories)

print("max1:", calories[-3])
print("max2:", calories[-2])
print("max3:", calories[-1])
print("--------------------------")
print("result: =", calories[-1] + calories[-2] + calories[-3])
print("--------------------------")
