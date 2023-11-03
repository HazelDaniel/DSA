#!/usr/bin/env python3


class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        return (self.min_swaps(row))

    def min_swaps(self, input_array):
        matrix = [[0] * len(input_array) for _ in range(len(input_array))]

        count = 0
        while (count < len(input_array) - 1):
            matrix[input_array[count]][input_array[count + 1]] = 1
            matrix[input_array[count + 1]][input_array[count]] = 1
            count += 1

        swaps = 0
        row_ind = 0
        while (row_ind <= len(matrix) // 2):
            col_ind = 0
            while (col_ind <= len(matrix[row_ind]) // 2):
                if ((abs(col_ind - row_ind) == 1) and
                        not (matrix[row_ind][col_ind] or
                             matrix[col_ind][row_ind])):
                    matrix[row_ind][col_ind] = 1
                    matrix[col_ind][row_ind] = 1
                    swaps += 1
                col_ind += 1
            row_ind += 1
        return (swaps - 1)


print(Solution().min_swaps([2, 0, 5, 4, 3, 1]))
