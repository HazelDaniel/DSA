#!/usr/bin/env python3
from collections import defaultdict


def find_highest(input_array):
    highest = input_array[0]
    for i in input_array:
        if (i > highest):
            highest = i
    return highest


def counting_sort(arr):
    count_arr = [0 for _ in range(find_highest(arr) + 1)]
    tmp_res = arr.copy()
    for i in arr:
        count_arr[i] += 1
    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]

    for i in arr:
        place_index = count_arr[i]
        tmp_res[place_index - 1] = i
        count_arr[i] -= 1
    return tmp_res


def num_to_equalize(arr):
    solution = 0
    occ_hash = defaultdict(int)
    sorted_arr = counting_sort(arr)
    length = len(sorted_arr)

    for i in arr:
        occ_hash[f"{i}"] += 1
    for index, i in enumerate(sorted_arr[-1:: -1]):
        if (index == length - 1):
            continue
        print(index, i)
    print(f"occurrence hash : {occ_hash}")
    return solution


print(num_to_equalize([5, 1, 3]))
