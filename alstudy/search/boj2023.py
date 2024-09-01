import math

# 입력 처리

n = int(input())

def is_prime(number):
    if number == 1:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True

first_n = [2, 3, 5, 7]
rest_n = [1, 3, 5, 7, 9]

def includes(arr, target):
    return target in arr

def search(n, depth, target):
    # base condition 1: 1자리 처리
    if n == 1 and depth == 1:
        return includes(first_n, int(target[depth - 1])) and is_prime(int(target))
    
    # base condition 2: 마지막 자리일 때
    if depth == n:
        return includes(rest_n, int(target[depth - 1])) and is_prime(int(target))

    # 첫번째 자리 확인
    if depth == 1 and includes(first_n, int(target[depth - 1])):
        return search(n, depth + 1, target)

    # 나머지 수 확인
    if not includes(rest_n, int(target[depth - 1])):
        return False

    if not is_prime(int(target[:depth])):
        return False

    return search(n, depth + 1, target)

begin = 10 ** (n - 1)
end = 10 ** n
answer = ''

for i in range(begin, end):
    target = str(i)
    if search(n, 1, target):
        answer += '\n' + target

print(answer.strip())
