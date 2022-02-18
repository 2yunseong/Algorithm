n = int(input())
count = 0
for h in range(0, n+1):
    for m in range(0, 60):
        for s in range(0, 60):
            if str(h).find('3') != -1:
                count = count + 1
            elif str(m).find('3') != -1:
                count = count + 1
            elif str(s).find('3') != -1:
                count = count + 1

print(count)
