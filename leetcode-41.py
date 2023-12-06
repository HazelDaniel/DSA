#!/usr/bin/env python3

from collections import defaultdict
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        positive_hash = defaultdict(int)
        glob_smallest = float('inf')
        curr_smallest = nums[0]
        smallest_positive = 1
        for i in nums:
            curr_smallest = i
            positive_hash[i] += 1
            if curr_smallest < glob_smallest and curr_smallest > 0:
                glob_smallest = curr_smallest
        if glob_smallest == float('inf') or glob_smallest > 1:
            return 1
        for i in nums:
            if i <= 0:
                smallest_positive = 1
                while positive_hash[smallest_positive]:
                    smallest_positive += 1
                return smallest_positive
            else:
                smallest_postiive = glob_smallest
                while positive_hash[smallest_positive]:
                    smallest_positive += 1
                return smallest_positive