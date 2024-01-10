from collections import defaultdict
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists):
        glob_list = []
        diff_hash = defaultdict(list)

        def str_(self):
            return f"{self.val}"

        def length_(self):
            count = 0
            curr = self
            while curr:
                curr = curr.next
                count += 1
            return count
        ListNode.__str__ = str_
        ListNode.__repr__ = str_
        ListNode.length = length_

        for i in lists:
            curr = i
            while curr:
                glob_list.append(curr)
                curr = curr.next
        glob_list = sorted(glob_list, key=lambda x: x.val)
        if not len(glob_list):
            return None
        l_max = glob_list[-1].val
        l_min = glob_list[0].val
        for i in glob_list:
            diff = l_max - i.val
            if diff_hash[diff]:
                diff_hash[diff][-1].next = i
            else:
                diff_hash[diff].append(i)
        i = 0
        prev = None
        prev_arr = []
        head = diff_hash[l_max - l_min][0]
        # print(f"diff hash is {diff_hash}")
        while i <= l_max - l_min:
            prev_arr = diff_hash[i]
            prev_arr[-1].next = prev
            prev = prev_arr[0]
            # print(f"prev value is {prev.val}")
            i += 1
        return head
