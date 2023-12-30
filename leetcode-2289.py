#!/usr/bin/env python3
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def length(self):
        current_node = self.head
        length = 0
        while current_node:
            length += 1
            print(f"value {current_node.data}")
            current_node = current_node.next
        return length

    def print_list(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=" -> ")
            current_node = current_node.next
        print("None")


def build_linked_list(array):
    linked_list = LinkedList()
    for element in array:
        linked_list.append(element)
    return linked_list


res_list = build_linked_list([5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11])
res_list.print_list()


class Solution:
    def totalSteps(self, nums):
        total_steps = self.calc_total_steps(build_linked_list(nums))
        return total_steps

    def calc_total_steps(self, list):
        if not list.head:
            return 0
        curr = list.head
        if not curr.next:
            return 0
        curr = list.head
        prev = curr
        curr = curr.next
        in_order = False
        steps = 0
        tmp = None
        while not in_order:
            pop_count = 0
            if not curr:
                break
            while curr:
                if (prev.data > curr.data):
                    in_order = False
                    # tmp = curr
                    # while tmp and tmp.data < prev.data:
                    #     pop_count += 1
                    #     print(f"temp data is {tmp.data}")
                    #     tmp = tmp.next
                    # prev.next = tmp
                    prev.next = curr.next
                    pop_count += 1
                if not curr.next:
                    # print(f"pop count is {pop_count}")
                    if not pop_count:
                        in_order = True
                        break
                    else:
                        steps += 1
                        curr = list.head
                        pop_count = 0
                prev = curr
                curr = curr.next
            list.print_list()
            if in_order:
                break
        return max(steps, 0)


answer = Solution().totalSteps([5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11])
answer = Solution().totalSteps([4,5,7,7,13])
answer = Solution().totalSteps([10,1,2,3,4,5,6,1,2,3])
print(answer)
