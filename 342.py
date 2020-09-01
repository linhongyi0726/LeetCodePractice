import math


class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num > 0 and math.log(num, 4).is_integer():
            return True
        return False


class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        elif num & (num - 1) != 0:
            return False
        else:
            return len(bin(num)) % 2 != 0


class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        elif len(bin(num)) % 2 != 0:
            return not any([int(char) for char in bin(num)[3:]])


class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        bin_num = bin(num)
        if num <= 0:
            return False
        elif len(bin_num) % 2 != 0:
            return bin_num.count('1') == 1


class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num == 0:
            return False
        while True:
            if num == 1:
                return True
            if num % 4 != 0:
                return False
            num = num / 4
