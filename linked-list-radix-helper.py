#!/usr/bin/env python3

class Node:
    """a class representation of a linked list node"""
    def __init__(self, value):
        self.value: int = value
        self.next: Node | None = None

    def __str__(self):
        return f"NODE: {self.value}"

    def __repr__(self):
        return self.__str__()


class List:
    """a class representation of a singly-linked list"""
    def __init__(self, num_array=[]):
        self.head: Node | None = None
        self.num_array: list[int] = num_array
        self.extract()

    def extract(self):
        prev = None
        curr = None
        for entry in reversed(self.num_array):
            curr = Node(entry)
            curr.next = prev
            prev = curr
        self.head = curr

    def append_node(self, value):
        new_node = Node(value)
        curr: Node | None = self.head
        while (curr and curr.next):
            curr = curr.next
        """this will always be true.
        python type anotation just wouldn't shut up"""
        if (curr):
            curr.next = new_node

    def print_list(self):
        curr: Node | None = self.head
        while (curr):
            print(curr)
            curr = curr.next


def extract_from_bins(bins: list[List | None]) -> list[int]:
    curr: Node | None = None
    acc_list = []
    for _, item in enumerate(bins):
        if not item:
            continue
        curr = item.head
        while (curr):
            acc_list.append(curr.value)
            curr = curr.next
    return acc_list


def insert_to_bin(bucket: list[List | None], curr: int, index_num: int):
    print(f"current index : {curr}\t item : {index_num}")
    existing = bucket[curr]
    new_node = Node(index_num)
    if (existing):
        curr_head = existing.head
        prev = None
        while (curr_head and curr_head.next and curr_head.value < index_num):
            prev = curr_head
            curr_head = curr_head.next
        if not curr_head:
            existing.head = Node(index_num)
            return
        if curr_head.next:
            if (prev):
                new_node.next = prev.next
                prev.next = new_node
            else:
                existing.head = new_node
        else:
            if curr_head.value > new_node.value:
                new_node.next = curr_head
                if (prev):
                    prev.next = new_node
                else:
                    existing.head = new_node
            else:
                curr_head.next = new_node
    else:
        bucket[curr] = List([index_num])


def find_highest(input_array):
    highest = float("-inf")
    for i in input_array:
        if (i > highest):
            highest = i
    return highest


def digit_count(num):
    count = 0
    if (num >= 0 and num <= 9):
        return 1

    while (num):
        num //= 10
        count += 1

    return count


def radix_sort(input_array: list):
    highest = find_highest(input_array)
    max_num_digit = digit_count(highest)
    base = 10
    dig_cut = 1

    bucket: list[List | None] = [None for _ in range(0, 10)]
    tmp_arr = input_array.copy()
    res_arr = tmp_arr

    while (max_num_digit):
        print("======")
        for i in tmp_arr:
            curr = (i // dig_cut) % base
            insert_to_bin(bucket, curr, i)
        tmp_arr = extract_from_bins(bucket)
        res_arr = tmp_arr.copy()
        dig_cut *= base
        max_num_digit -= 1
        print("======")
    return res_arr


print(radix_sort([20, 900, 3, 4, 4, 5]))
