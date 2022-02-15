n = int(input())

command_list = map(str, input().split())

current_x = 1
current_y = 1

direction_list = ["U", "D", "L", "R"]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for command in command_list:
    index = 0
    for i in range(4):
        if command == direction_list[i]:
            index = i
            break
    next_x = current_x + dx[i]
    next_y = current_y + dy[i]

    if 1 > next_x or n < next_x or 1 > next_y or n < next_y:
        continue
    else:
        current_x = next_x
        current_y = next_y

print(current_x, current_y)
