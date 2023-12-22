#!/usr/bin/env python3
"""
For every entry in the array:
    we calculate the two sum values that add up to x, where x + entry = 0
    - have a two-sum helper
"""
arr = [-1, 0, 1, 2, -1, -4]  # [[-1, 0, 1], [-1, -1, 2]]
# arr = [0, 1, 1] # []
# arr = [1, 2, -2, -1] # []
# arr = [3, -2, 1, 0]
# arr = [-2, 0, 1, 1, 2]
# arr = [-1, 0, 1]
# arr = [1, 2, -2, -1]
# arr = [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]
arr = [-1, 0, 1, 0]


class Solution:
    def two_sum(self, array, target, acc_ind, start, end, super_set):
        """this is the two sum approach"""
        i, j = 0 if acc_ind else 1, end
        acc = array[acc_ind]
        while i < j:
            if array[i] + array[j] + acc == target:
                x = tuple(sorted((acc, array[i], array[j])))
                if x:
                    super_set.add(x)
                j = j - 1 if not j - 1 == acc_ind else j - 2
                i = i + 1 if not i + 1 == acc_ind else i + 2
            else:
                if (array[i] + array[j] + acc) > target:
                    if array[i] > array[j]:
                        i = i + 1 if not i + 1 == acc_ind else i + 2
                    else:
                        j = j - 1 if not j - 1 == acc_ind else j - 2
                else:
                    if array[i] < array[j]:
                        i = i + 1 if not i + 1 == acc_ind else i + 2
                    else:
                        j = j - 1 if not j - 1 == acc_ind else j - 2
            if j == -1 or i == len(array):
                return ()

    def threeSum(self, nums):
        array = sorted(nums)
        super_set = set()
        i, max = 0, len(nums) - 1
        j = max
        while i <= j - 2:
            self.two_sum(array, 0, i, i + 1, j, super_set)
            i += 1
        return list(super_set)


# print(Solution().two_sum(arr, 0, 1, 0, len(arr) - 1))
print(Solution().threeSum(arr))
