class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        start = 0
        end = x
        while end - start > 1:
            mid = (start + end) // 2
            if mid**2 == x:
                return mid
            elif mid**2 > x:
                end = mid
            elif mid**2 < x:
                start = mid
        return start


# Newton's method
class Solution:
    def mySqrt(self, x: int) -> int:
        sqrt = x
        while sqrt**2 > x:
            sqrt = (sqrt + x / sqrt) // 2
        return int(sqrt)


class Solution:
    def mySqrt(self, x: int) -> int:
        return int(x**0.5)
