#!/usr/bin/env python3
class Solution:
    def combinationSum(self, candidates, target):
        look_hash = dict()
        super_array = []
        sum_hash = dict()
        factor_hash = dict()
        combination_hash = dict()

        for el in candidates:
            look_hash[el] = 1

        reversed_keys = set(reversed(candidates))

        def factor_in_array(target):
            in_array = 0
            for i in reversed_keys:
                if (not target % i and target > i):
                    in_array = i
            return in_array

        for el in look_hash.keys():
            combination = []
            diff = target - el

            if (not target % el and target != el and factor_hash.get(el, 0) != el):
                number = target / el
                count = 0
                combination_key = ""
                while (count < number):
                    combination.append(el)
                    combination_key += f"{el}"
                    count += 1
                if (combination_key not in combination_hash):
                    super_array.append(combination)
                combination_hash[combination_key] = 1
                combination = []
                factor_hash[el] = count

            if (not diff):
                combination.append(el)
                super_array.append(combination)
                continue

            if (sum_hash.get(el, 0) == el or factor_hash.get(el, 0) == diff):
                continue

            if (diff in look_hash):
                if (el < diff):
                    combination.append(el)
                    combination.append(diff)
                    combination_key = f"{el}{diff}"
                else:
                    combination.append(diff)
                    combination.append(el)
                    combination_key = f"{diff}{el}"
                sum_hash[el] = diff
                if (combination_key not in combination_hash):
                    super_array.append(combination)
                combination_hash[combination_key] = 1
                combination = []

            factor = factor_in_array(diff)
            if (factor and factor_hash.get(diff, 0) != diff):
                number = diff // factor
                while (factor and factor_hash.get(number, 0) != factor):
                    number = diff // factor
                    combination = [factor for _ in range(number)]
                    combination_key = "".join([str(i) for i in combination])
                    if (diff in look_hash and (number * diff <= target)):
                        if (diff < factor):
                            combination_key = f"{diff}" + combination_key
                        else:
                            combination_key += f"{diff}"
                        combination.append(diff)
                    else:
                        if (el < factor):
                            combination_key = f"{el}" + combination_key
                        else:
                            combination_key += f"{el}"
                        combination.append(el)
                    factor_hash[factor] = number
                    if (combination_key not in combination_hash):
                        super_array.append(combination)
                    combination = []
                    factor = factor_in_array(factor)
            if (len(combination)):
                super_array.append(combination)
        return super_array

candidates = [8,7,4,3]
target = 11
candidates = [2,3,5]
target = 8
# candidates = [2,3]
# target = 6
# candidates = [2,3, 6, 7]
# target = 7
# candidates = [3, 5, 7]
# target = 10
print(Solution().combinationSum(candidates, target))

# candidates = [8,7,4,3] # 11 # [[8,3],[7,4],[4,4,3]]
# candidates = [3,5,7] # 10 # [[3,7],[5,5]]
# candidates = [2,3] # 6 # [[2,2,2],[3,3]]
# candidates = [2] # 1 # []
# candidates = [2,3,5] # 8 # [[2,2,2,2],[2,3,3],[3,5]]
# candidates = [2,3,6,7] # 7 # [[2,2,3],[7]]
