#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def doubleIt(self, head):
        acc = ""
        curr = head
        prev = None
        while (curr):
            acc += str(curr.val)
            curr = curr.next

        curr = head
        res = str(int(acc) * 2)
        i = 0
        while (curr):
            curr.val = res[i]
            prev = curr
            curr = curr.next
            i += 1

        if (i < len(res)):
            self.append_string_to_list(prev, i - 1, res)
        return head

    def append_string_to_list(self, tail, index, string):
        tmp = tail
        prev = None
        while (tmp):
            tmp.val = string[index]
            prev = tmp
            index += 1
            tmp = tmp.next
            if (prev):
                # print(f"we have prev and it is {prev.val}")
                # print(f"index is {index}")
                prev.next = ListNode(int(string[index]))


def printLinkedList(head, get_size=False):
    current = head
    count = 0
    while current:
        if (not get_size):
            print(current.val, end=" -> ")
        current = current.next
        count += 1
    if (not get_size):
        print("None")
    return count


head = ListNode(9)
head.next = ListNode(9)
head.next.next = ListNode(9)
# head.next.next.next = ListNode(4)
# head.next.next.next.next = ListNode(5)

printLinkedList(Solution().doubleIt(head))
