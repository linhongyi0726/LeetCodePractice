class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []
        digits.reverse()
        for i in range(len(digits)):
            if digits[i] == 9:
                if i < len(digits) - 1:
                    res.append(0)
                else:
                    res.extend([0, 1])
            else:
                digits[i] += 1
                res.extend(digits[i:])
                break
        res.reverse()
        return res


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = ''
        for digit in digits:
            num += str(digit)
        num = int(num) + 1
        return [v for v in str(num)]
