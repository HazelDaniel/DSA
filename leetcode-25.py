#!/usr/bin/python3
# Definition for singly-linked list.
from collections import defaultdict


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return f"{self.val}"

    def __repr__(self):
        return f"{self.val}"

    def length(self, stop=-1):
        curr = self
        count = 0
        while curr:
            if stop != - 1 and count == stop:
                return count
            count += 1
            curr = curr.next
        return count


class Solution:
    def reverseKGroup(self, head, k):
        pass_count = 0
        mod_count = 0
        pass_hash = defaultdict(list)

        # def get_len(self, stop=-1):
        #     curr = self
        #     count = 0
        #     while curr:
        #         if stop != - 1 and count == stop:
        #             return count
        #         count += 1
        #         curr = curr.next
        #     return count

        if head.length(k) < k:
            return head
        curr = head
        prev = None
        while curr:
            pass_hash[pass_count].append(curr)
            # print(f"mod count: {mod_count}, pass count: {pass_count}")
            if not mod_count and pass_count:
                if prev:
                    prev.next = None
            if mod_count == k - 1:
                pass_count += 1
                # if prev:
                #     print(f"blocking point is {prev}")
            mod_count = (mod_count + 1) % k
            prev = curr
            curr = curr.next
        x = pass_count
        prev = None
        tail = None
        print(pass_hash)
        # print("--------")
        while x >= 0:
            # print(f"prev was {prev}")
            tmp = prev
            # pass_hash[x][0]
            if not pass_hash[x]:
                x -= 1
                continue
            if x == pass_count and pass_hash[x][0].length(k) < k:
                prev, tail = pass_hash[x][0], pass_hash[x][-1]
            else:
                prev, tail = self.reverse_list(pass_hash[x][0])
            # print("<>>><><><><><><>")
            # print_list(prev)
            # print("<>>><><><><><><>")
            tail.next = tmp
            # if prev:
            if not x:
                head = prev
            x -= 1
        return head

    def reverse_list(self, head):
        if not head:
            return head
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            if not next:
                return curr, head
            curr = next
        return head, head


def print_list(node):
    curr = node
    while (curr):
        print(f"{curr.val}", end=" ")
        curr = curr.next
    if node:
        print()


new_node = ListNode(1, ListNode(2, ListNode(3,
                                            ListNode(4, ListNode(5, None)))))
new_node = ListNode(1, ListNode(2, None))
answer = Solution().reverseKGroup(new_node, 2)
print("=====answer=====")
print_list(answer)
