class Solution:
    def countAndSay(self, n: int) -> str:
        res = '1'
        for i in range(n - 1):
            ans = ''
            count = 1
            for j in range(len(res)):
                if j + 1 < len(res) and res[j] == res[j + 1]:
                    count += 1
                    continue
                ans += str(count) + res[j]
                count = 1
            res = ans
        return res


class Solution:
    def countAndSay(self, n: int) -> str:
        res = '1'
        for i in range(n - 1):
            ans = ''
            pre = res[0]
            count = 1
            for j in range(len(res)):
                if j + 1 < len(res) and pre == res[j + 1]:
                    count += 1
                    continue
                ans += str(count) + pre
                count = 1
                if j + 1 < len(res):
                    pre = res[j + 1]
            res = ans
        return res
