n, m = map(int, input().split())
global_max = -1

for i in range(n):
    row_arr = list(map(int, input().split()))
    local_min = 999999
    for j in range(m):
        if(local_min > row_arr[j]):
            local_min = row_arr[j]
    if global_max < local_min:
        global_max = local_min

print(global_max)
