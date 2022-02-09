n, m, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

answer = 0
max_arr = [arr[len(arr)-1], arr[len(arr)-2]]

count = 0
for i in range(m):
    if count >= k:
        answer += max_arr[1]
        count = 0
        continue
    answer += max_arr[0]
    count += 1

print(answer)
