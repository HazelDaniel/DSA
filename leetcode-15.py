#!/usr/bin/env python3
"""
For every entry in the array:
    we calculate the two sum values that add up to x, where x + entry = 0
    - have a two-sum helper
"""
arr = [-1, 0, 1, 2, -1, -4] # [[-1, 0, 1], [-1, -1, 2]]
# arr = [0, 1, 1] # []
# arr = [1, 2, -2, -1] # []
# arr = [3, -2, 1, 0]


class Solution:
    def two_sum(self, array, target, acc_ind, start, end):
        i, j = start, end
        acc = array[acc_ind]
        while i < j:
            if array[i] + array[j] + acc == target:
                return array[i], array[j]
            else:
                if (array[i] + array[j] + acc) > target:
                    if array[i] > array[j]:
                        i = i + 1 if not i == acc_ind else i + 2
                    else:
                        j = j - 1 if not j == acc_ind else j - 2
                else:
                    if array[i] < array[j]:
                        i = i + 1 if not i == acc_ind else i + 2
                    else:
                        j = j - 1 if not j == acc_ind else j - 2
            if j <= i or (i < 0 or j < 0):
                return ()

    def threeSum(self, nums):
        array = sorted(nums)
        super_array = []
        i, max = 0, len(nums) - 1
        while i < max - 1:
            j = max
            while j > i:
                x = self.two_sum(array, 0, i, i + 1, j)
                if x and sorted([array[i], *x]) not in super_array:
                    super_array.append(sorted([array[i], *x]))
                j -= 1
            i += 1
        return super_array





# print(Solution().two_sum(arr, 0, 1, 0, len(arr) - 1))
print(Solution().threeSum(arr))
