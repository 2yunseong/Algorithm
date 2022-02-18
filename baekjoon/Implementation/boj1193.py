from numpy import right_shift


left_count = 1
right_count = 1
iteration_number = 1

n = int(input())

while n != 0:
    if iteration_number == left_count:
        iteration_number = iteration_number + 1
        left_count = 1
        right_count = iteration_number
        n = n - 1
    else:
        left_count = left_count + 1
        right_count = right_count - 1
        n = n - 1

print(str(left_count) + '/' + str(right_count))
