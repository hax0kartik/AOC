
f = open('input.txt', 'r')
data = f.readlines()

total = 0
arr = []
for line in data:
    if(line.strip() == ""):
        arr.append(total)
        total = 0
    else:
        total += int(line.strip())

print("Max is", max(arr))