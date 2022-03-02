from time import sleep


def change_direction(current_direction):
    if current_direction == 0:
        return 3
    else:
        return current_direction - 1


def back_direction(current_direction):
    if current_direction == 0:
        return 2
    elif current_direction == 1:
        return 3
    else:
        return current_direction - 2


def set_next(a, b, direction):
    if direction == 3:
        a = a + dy[1]
        b = b + dx[1]
    elif direction == 2:
        a = a + dy[2]
        b = b + dx[2]
    elif direction == 1:
        a = a + dy[0]
        b = b + dx[0]
    else:
        a = a + dy[3]
        b = b + dx[3]

    return a, b


# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
count = 0
next_a = 0
next_b = 0

n, m = map(int, input().split())
a, b, direction = map(int, input().split())

board = []
is_visited = [[0] * m for _ in range(n)]  # 0 :아직 안들림 1 : 들림


for i in range(n):
    board.append(list(map(int, input().split())))

is_visited[b][a] = 1
count = count + 1

while True:
    is_move = False
    for i in range(4):
        direction = change_direction(direction)
        next_a, next_b = set_next(a, b, direction)
        # 바다 거나, 들렸던 칸이면
        if board[next_b][next_a] == 1 or is_visited[next_b][next_a] == 1:
            print("바다거나, 들렸던 칸임: [%d, %d]" % (next_b, next_a))
            sleep(1)
            continue
        else:
            print("방문: [%d, %d]" % (next_b, next_a))
            sleep(1)
            count = count + 1
            a = next_a
            b = next_b
            is_visited[next_b][next_a] = 1
            is_move = True
            break
    next_a, next_b = set_next(a, b, back_direction(direction))
    if board[next_b][next_a] == 1:
        break
    elif is_move == False:
        a = next_a
        b = next_b
        print("뒤로가기: [%d, %d]" % (next_b, next_a))
        sleep(1)


print(count)
# 1. 방향 바꾸기
