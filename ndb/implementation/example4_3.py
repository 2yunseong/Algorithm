# index 0 ~ 7
x_axis = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
y_axis = [1, 2, 3, 4, 5, 6, 7, 8]

dx = [-1, 1, -1, 1, 2, 2, -2, -2]
dy = [-2, -2, 2, 2, 1, -1, -1, 1]

count = 0

place = input()

x_point_idx = x_axis.index(place[0])
y_point_idx = y_axis.index(int(place[1]))

for i in range(8):
    next_x_idx = x_point_idx + dx[i]
    next_y_idx = y_point_idx + dy[i]

    if next_x_idx < 0 or next_x_idx > 7 or next_y_idx < 0 or next_y_idx > 7:
        continue
    count = count + 1

print(count)
