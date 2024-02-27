#!/usr/bin/env python3

class Solution:
    def combinationSum(self, candidates, target):
        look_hash = dict()
        super_array = []
        local_hash = dict()

        def factor_in_array(target):
            in_array = 0
            for i in look_hash.keys():
                if (not target % i):
                    in_array = i
            return in_array

        for el in candidates:
            look_hash[el] = 1

        for el in look_hash.keys():
            combination = []
            diff = target - el

            if (not diff):
                combination.append(el)

            # elif (not target % el):
            #     number = target / el
            #     count = 0
            #     while (count < number):
            #         combination.append(el)
            #         count += 1
            #     combination.append(diff)

            elif (diff in look_hash and diff not in local_hash):
                combination.append(diff)
                combination.append(el)
                local_hash[diff] = 1

            else:
                factor = 0
                factor = factor_in_array(diff)
                if factor:
                    number = diff / factor
                    count = 0
                    while (count < number):
                        combination.append(factor)
                        count += 1
                    combination.append(diff)
            if (len(combination)):
                super_array.append(combination)
        return super_array
