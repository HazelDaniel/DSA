#!/usr/bin/env python3
OOB_MESSAGE = "out of fenwick bounds"


class Fenwick:
    def __init__(self, array):
        """O(1)"""
        self.array = [0]
        self.array.extend(array)

    def get(self, idx):
        """O(1)"""
        if idx > 0 and idx < len(self.array):
            return self.array[idx]
        else:
            raise Exception(OOB_MESSAGE)

    def set(self, idx, value):
        """O(1)"""
        if idx > 0 and idx < len(self.array):
            self.array[idx] = value
        else:
            raise Exception(OOB_MESSAGE)

    def sum(self, i):
        """ O(log(n))"""
        s = 0

        while i > 0:
            s += self.get(i)
            i -= (i & -i)
        return s

    @property
    def length(self):
        """O(1)"""
        return len(self.array)

    def add(self, i, val):
        """O(log(n))"""
        while i < self.length:
            parent = i + (i & -i)
            self.set(i, self.get(i) + val)
            i += parent

    def subtract(self, i, val):
        """O(log(n))"""
        while (i < self.length):
            parent = i + (i & -i)
            self.set(i, max(self.get(i) - val, 0))
            i += parent

    @classmethod
    def construct(cls, array):
        """O(n)"""
        f = cls(array)

        i = 1
        while i < len(f.array):
            parent = i + (i & -i)

            if (parent < len(f.array)):
                f.set(parent, f.get(parent) + f.get(i))

            i += 1

        return f

    def __str__(self):
        return f"<{self.array[1:]}>"


"""
example:
    construct([5, 2, 9, -3, 5, 20])
    1. [  5] -> 0001                        -> [  5]
    2. [  2] -> 0010 -> [2 + 5]             -> [  7]
    3. [  9] -> 0011                        -> [  9]
    4. [ -3] -> 0100 -> [ -3 + 9 + 2 + 5]   -> [ 13]
    5. [  5] -> 0101                        -> [  5]
    6. [ 20] -> 0110 -> [ 20 + 5]           -> [ 25]

    // sum for log(N) (the value of the least significant bit) times
"""


if __name__ == "__main__":
    tree = Fenwick.\
        construct([5, 2, 9, -3, 5, 20, 10, -7, 2, 3, -4, 0, -2, 15, 5])
    print(f"sum is {tree.sum(15)}")
    print(f"before adding 5 to [3]: {tree}")
    tree.add(3, 5)
    print(f"after adding 5 to [3]: {tree}")
    print()
    print(f"sum is {tree.sum(15)}")
    print(f"before removing 5 from [3]: {tree}")
    tree.subtract(3, 5)
    print(f"after removing 5 from [3]: {tree}")
    print(f"sum is {tree.sum(15)}")

    print(f"before removing 90 from [2]: {tree}")
    tree.subtract(2, 80)
    print(f"after removing 90 from [2]: {tree}")
    print(f"sum is {tree.sum(15)}")
