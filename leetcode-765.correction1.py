#!/usr/bin/env python3

class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        return (self.min_swaps(row))

    def swap(self, i, j, row):
        tmp = row[i]
        row[i] = row[j]
        row[j] = tmp

    def min_swaps(self, row):
        partner = [i for i in range(len(row))]
        position = [i for i in range(len(row))]

        for i in range(len(row)):
            if i % 2:
                partner[i] = i - 1
            else:
                partner[i] = i + 1
            position[row[i]] = i

        i = 0
        res = 0
        while (i < len(row)):
            j = partner[position[partner[row[i]]]]
            while (True):
                if (j == i):
                    break
                self.swap(i, j, row)
                self.swap(row[i], row[j], position)
                res += 1
                j = partner[position[partner[row[i]]]]
            i += 1
        return (res)


print(Solution().min_swaps([2, 0, 1, 3]))
