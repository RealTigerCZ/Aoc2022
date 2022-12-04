if 0:
    INPUT_FILE = "input_simple.txt"
else:
    INPUT_FILE = "input.txt"


count = 0

with open(INPUT_FILE, "r") as file:
    for line in file.readlines():
        data = [[int(j) for j in i.split("-")] for i  in line.split(",")]
        
        if data[0][0] >= data[1][0] and data[0][1] <= data[1][1]:
            count += 1
        
        elif data[1][0] >= data[0][0] and data[1][1] <= data[0][1]:
            count += 1
        
print(count)
        
