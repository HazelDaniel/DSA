#!/usr/bin/env python3

class Node:
    """a class representation of a linked list node"""
    def __init__(self, value):
        self.value: int = value
        self.next: Node | None = None

    def __str__(self):
        return f"{self.value}"

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


linked_list = List([1, 2, 3])
linked_list.print_list()
