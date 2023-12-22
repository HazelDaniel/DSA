#!/usr/bin/env python3

arr = [1, 0, -1, 0, -2, 2]
# arr = [1, 4, -2, -8, 6, 1, 7, -8, -4, -5, -9, 0, 4, -9, 3, 5, -8, 1, 9]
arr = [2, 2, 2, 2, 2]
arr = [2, 2, 2, 2, 2, 2, 2, 2, 2]


class Solution(object):
    def two_sum(self, array, target,
                acc1_ind, acc2_ind, end, super_set, sum_dict):
        """this is the two sum approach"""
        i, j = 0, end
        while (i == acc1_ind) or (i == acc2_ind):
            # print("recalibrating")
            i = (i + 1) % len(array)
        while (j == acc1_ind) or (j == acc2_ind):
            # print("recalibrating")
            j = (j - 1) % len(array)
        acc = array[acc1_ind] + array[acc2_ind]
        while i < j:
            # print(f"\taccumulator: {acc}, left: {array[i]},"
            #       f"right: {array[j]}, target: {target}")
            if array[i] + array[j] + acc == target:
                x = tuple(sorted((array[acc1_ind], array[acc2_ind],
                                  array[i], array[j])))
                if x:
                    sum_dict[(array[i], array[j])] = acc
                    super_set.add(x)
                i += 1
                while (i == acc1_ind) or (i == acc2_ind):
                    # print("recalibrating")
                    i = (i + 1) % len(array)
                j -= 1
                while (j == acc1_ind) or (j == acc2_ind):
                    # print("recalibrating")
                    j = (j - 1) % len(array)
            else:
                if (array[i] + array[j] + acc) > target:
                    if array[i] > array[j]:
                        i += 1
                        while (i == acc1_ind) or (i == acc2_ind):
                            # print("recalibrating")
                            i = (i + 1) % len(array)
                    else:
                        j -= 1
                        while (j == acc1_ind) or (j == acc2_ind):
                            # print("recalibrating")
                            j = (j - 1) % len(array)
                else:
                    if array[i] < array[j]:
                        i += 1
                        while (i == acc1_ind) or (i == acc2_ind):
                            # print("recalibrating")
                            i = (i + 1) % len(array)
                    else:
                        j -= 1
                        while (j == acc1_ind) or (j == acc2_ind):
                            # print("recalibrating")
                            j = (j - 1) % len(array)
            if j == -1 or i == len(array):
                return ()

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        array = sorted(nums)
        super_set = set()
        arr_len = len(nums)
        sum_dict = dict()
        i, j = 0, arr_len - 1
        if arr_len < 4:
            return ()
        while (i <= j):
            ii, jj = i + 1, arr_len - 1
            while (ii <= jj):
                sum1 = array[i] + array[ii]
                x = tuple(sorted([array[i], array[ii]]))
                if x in sum_dict:
                    if sum_dict[x] == sum1 and array[i] != array[ii]:
                        ii += 1
                        continue
                self.two_sum(array, target, i,
                             ii, ii, super_set, sum_dict)
                ii += 1
            i += 1
        return list(super_set)


# answer = Solution().fourSum(arr, 0)
answer = Solution().fourSum(arr, 8)
# answer = Solution().fourSum(arr, -17)
print()
print(answer)
