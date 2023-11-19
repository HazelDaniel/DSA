#!/usr/bin/env python3
from typing import List


class Node:
    """a class representation of a linked List node"""
    def __init__(self, value):
        self.value: int = value
        self.next: Node | None = None

    def __str__(self):
        return f"NODE: {self.value}"

    def __repr__(self):
        return self.__str__()


class LinkedList:
    """a class representation of a singly-linked List"""
    def __init__(self, num_array=[]):
        self.head: Node | None = None
        self.num_array: List[int] = num_array
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

    def print_List(self):
        curr: Node | None = self.head
        while (curr):
            curr = curr.next


def extract_from_bins(bins: List[LinkedList | None]) -> List[int]:
    curr: Node | None = None
    acc_List = []
    for _, item in enumerate(bins):
        if not item:
            continue
        curr = item.head
        while (curr):
            acc_List.append(curr.value)
            curr = curr.next
    return acc_List


def clear_bins(bins: List[LinkedList | None]):
    curr: Node | None = None
    prev: Node | None = None
    for i, item in enumerate(bins):
        if not item:
            continue
        curr = item.head
        while (curr):
            prev = curr
            curr = curr.next
            del prev
        bins[i] = None


def insert_to_bin(bucket: List[LinkedList | None], curr: int, index_num: int):
    existing = bucket[curr]
    new_node = Node(index_num)
    if (existing):
        curr_head = existing.head
        while (curr_head and curr_head.next):
            curr_head = curr_head.next
        if (curr_head):
            curr_head.next = new_node
    else:
        bucket[curr] = LinkedList([index_num])


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


def radix_sort(input_array: List[int]):
    highest = find_highest(input_array)
    max_num_digit = digit_count(highest)
    base = 10
    dig_cut = 1

    bucket: List[LinkedList | None] = [None for _ in range(0, 10)]
    tmp_arr = input_array.copy()
    res_arr = tmp_arr

    while (max_num_digit):
        for i in tmp_arr:
            curr = (i // dig_cut) % base
            insert_to_bin(bucket, curr, i)
        tmp_arr = extract_from_bins(bucket)
        clear_bins(bucket)
        res_arr = tmp_arr.copy()
        dig_cut *= base
        max_num_digit -= 1
    return res_arr


print(radix_sort([20, 900, 3, 4, 4, 5, 1020]))
