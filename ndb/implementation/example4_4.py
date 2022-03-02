from re import T


def change_direction(current_direction):
    if current_direction == 0:
        return 3
    else:
        return current_direction - 1


def back_direction(current_direction):
    return 10


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

board = [[0] * m for _ in range(n)]
is_visited = [[0] * m for _ in range(n)]  # 0 :아직 안들림 1 : 들림
for i in range(n):
    board.append(list(map(int, input().split())))

while True:
    is_move = False
    for i in range(4):
        direction = change_direction(direction)
        next_a, next_b = set_next(a, b, direction)
        # 바다 거나, 들렸던 칸이면
        if board[next_b][next_a] == 1 or is_visited[next_b][next_a] == 1:
            continue
        else:
            count = count + 1
            a = next_a
            b = next_b
            is_move = True
            break
    if is_move == False & &
    # 1. 방향 바꾸기
