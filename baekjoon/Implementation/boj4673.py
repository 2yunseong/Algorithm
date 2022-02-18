self_number_list = [0] * 10001

for i in range(1, 10001):
    temp = i
    target = str(i)
    for e in target:
        temp += int(e)

    if temp > 10000:
        continue
    else:
        self_number_list[temp] = 1

for i in range(1, 10001):
    if self_number_list[i] == 0:
        print(i)
