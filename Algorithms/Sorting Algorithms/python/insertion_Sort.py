def insertion_sort(n):
    for i in range(1, len(n)):
        to_insert = n[i]
        j = i - 1
        while j >= 0 and n[j] > to_insert:
            n[j + 1] = n[j]
            j -= 1
        n[j + 1] = to_insert

check_nums = [51, 1, 125, 4, 5]
insertion_sort(check_nums)
print(check_nums)