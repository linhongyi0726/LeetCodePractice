class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = int(a, 2)
        b = int(b, 2)
        res = bin(a + b)[2:]
        return res


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        len_a = len(a)
        len_b = len(b)
        if len_a > len_b:
            b = '0' * (len_a - len_b) + b
        else:
            a = '0' * (len_b - len_a) + a
        carry = 0
        res = ''
        for i in range(len(a) - 1, -1, -1):
            sum = int(a[i]) + int(b[i]) + carry
            if sum > 1:
                carry = sum // 2
                sum = sum % 2
            else:
                carry = 0
            res = str(sum) + res
        if carry == 1:
            res = '1' + res
        return res
