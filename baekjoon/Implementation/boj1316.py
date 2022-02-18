number_of_group_word = 0

n = int(input())

for i in range(n):
    target_str = input()
    success_flag = True
    already_exist_flag_list = []
    group_enable_alphabet = ''

    for j in range(len(target_str)):
        if j == 0:
            group_enable_alphabet = target_str[j]
            already_exist_flag_list.append(target_str[j])
            continue
        if group_enable_alphabet == target_str[j]:
            continue
        if target_str[j] in already_exist_flag_list:
            success_flag = False
            break
        group_enable_alphabet = target_str[j]
        already_exist_flag_list.append(target_str[j])

    if success_flag:
        number_of_group_word = number_of_group_word + 1

print(number_of_group_word)
