#!/usr/bin/env python3

"""
1. assume the smaller of the two arrays (A and B) to be A
2. initialize the left and right sub-arrays based on the array A
    - the left initialized to zero
    - the right initialized to len(A)
=== set the following in a while loop based on (left <= right) ===
3.  compute the partition for both arrays assuming they have already been merged into the larger array (sorted (A + B))
    partitionA = (left + right) // 2
    PartitionB = ((n + m + 1) // 2) - partitionA
4. compute the maximum at A.left , minimum at A.right, maximum at B.left  and minimum at B.right
    maxA = A[partitionA - 1] if partitionA not <= 0 else -infinity
    minA = A[partitionA] if partitionA < len(A) else infinity
    maxB = B[partitionB - 1] if partitionB not <= 0 else -infinity
    minB = B[partitionB] if partitionB < len(B) else infinity
5. if maxA <= minB and maxB <= minA, then we have found the right partition. so:
    - if the final array is even in length, then we find the median from: (max(maxA, maxB) + min(minA, minB)) / 2
    - else:
        we return max(maxA, maxB)
6. else, test for these cases:
    - if maxA > minB:
        then we know that maxA is too large to be on the left side of the partition, so:
        we move it to the right by recalibrating the partition to the left
    - maxB > minA:
        then we know that minA is too small to be on the right side of the partition, so:
        we move it to the left side by recalibrating the partition to the right
"""
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        left, right = 0, len(nums1)

        while left <= right:
            partition_a = (left + right) // 2
            partition_b = (len(nums1) + len(nums2) + 1) // 2 - partition_a
            max_a = nums1[partition_a - 1] if not partition_a <= 0 else float('-inf')
            min_a = nums1[partition_a] if not partition_a >= len(nums1) else float('inf')
            max_b = nums2[partition_b - 1] if not partition_b <= 0 else float('-inf')
            min_b = nums2[partition_b] if not partition_b >= len(nums2) else float('inf')
            if max_a <= min_b and max_b <= min_a:
                if (len(nums1) + len(nums2)) % 2 == 0:
                    result = (max(max_a, max_b) + min(min_a, min_b)) / 2
                    return result
                else:
                    return max(max_a, max_b)
            else:
                if max_a > min_b:
                    right = partition_a - 1
                elif max_b > min_a:
                    left = partition_a + 1
                else:
                    print("unhandled edge case!")
                    return float('-inf')
solution = Solution()
print(solution.findMedianSortedArrays([1, 2], [3, 4]))
