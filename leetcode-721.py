#!/usr/bin/env python3

class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        mail_hash = dict()
        for idx, i in enumerate(accounts):
            for j in range(1, len(i)):
                if (not mail_hash.get(i[j], None)):
                    mail_hash[i[j]] = set()
                mail_hash[i[j]].add(idx)

        mail_set = set()
        res_hash = dict()
        for i, ii in mail_hash.items():
            tmp = set()
            for j in mail_hash[i]:
                if j not in mail_set:
                    tmp = set()
                    tmp.add(accounts[j][0])
                    tmp.add(i)
                    res_hash[j] = tmp
                else:
                    if (res_hash.get(j, None)):
                        res_hash[j].add(i)
                    else:
                        print(list(mail_set))
                        res_hash[list(mail_set)[0]].add(i)
                mail_set.update(ii)
        return [sorted(list(i)) for i in res_hash.values()]


accounts = [["John", "johnsmith@mail.com", "john_newyork@mail.com"],
            ["John", "johnsmith@mail.com", "john00@mail.com"],
            ["Mary", "mary@mail.com"],
            ["John", "johnnybravo@mail.com"]]
print(Solution().accountsMerge(accounts))
