h, w, n = map(int, input().split())
floor = 0
room_num = 0

while n != 0:
    for r in range(w):
        for f in range(h):
            floor = f + 1
            room_num = r + 1
            n = n - 1
            if n == 0:
                break


print("%d %d" % (floor, room_num))
