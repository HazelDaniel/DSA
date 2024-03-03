#!/usr/bin/env python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head, n):
        count = 1
        size = self.printLinkedList(head, True)
        prev = None
        tmp = head

        if (n == size):
            if (tmp.next):
                tmp = tmp.next
                return tmp
            else:
                return None

        while (count <= size - n and tmp):
            prev = tmp
            tmp = tmp.next
            count += 1

        if (prev):
            prev.next = tmp.next
        return head

    def printLinkedList(self, head, get_size=False):
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

    # def reverse_list


head = ListNode(1)
# [1]
# count = 1
# 1 - 1 = 0

# head.next = ListNode(2)
# head.next.next = ListNode(3)
# head.next.next.next = ListNode(4)
# head.next.next.next.next = ListNode(5)

print("Original Linked List:")
Solution().printLinkedList(Solution().removeNthFromEnd(head, 1))

# Remove the second node from the end
solution = Solution()
new_head = solution.removeNthFromEnd(head, 2)
