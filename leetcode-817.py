#!/usr/bin/env python3

class Solution:
    def convert_to_arr(self, linked_list):
        """this converts a linked list to an array"""
        tmp = linked_list
        res_arr = []
        while tmp:
            res_arr.append(tmp.val)
            tmp = tmp.next
        return res_arr

    def numComponents(self, head, nums):
        """my solution"""
        i = 0
        j = 0
        super_array = []
        res_head = self.convert_to_arr(head)
        while j < len(res_head):
            if i >= len(nums):
                i = len(nums) - 1
            if nums[i] == res_head[j]:
                array_to_push = []
                while i < len(nums) and nums[i] == res_head[j]:
                    array_to_push.append(nums[i])
                    j = j + 1
                    i = i + 1
                print(j, i)
                super_array.append(array_to_push)
                print(array_to_push, i, j)
            else:
                j += 1
        print(super_array)
        return len(super_array)


print(Solution().numComponents([0, 1, 2, 3],  [0, 1, 3]))
