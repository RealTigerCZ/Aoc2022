if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


count = 0

with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        data = [[int(j) for j in i.split("-")] for i in line.split(",")]
        
        x = set(range(data[0][0], data[0][1] + 1))
        y = set(range(data[1][0], data[1][1] + 1))
        
        if not x.isdisjoint(y):
            count += 1
        
print(count)
