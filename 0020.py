"""
    Use stack to match left/right brackets
    T: O(n)/S: O(n)
"""
class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {'(': ')', '[': ']', '{': '}'}
        stack = []
        for char in s:
            if char in mapping:
                stack.append(char)
            elif stack == []:
                return False
            else:
                if mapping[stack.pop()] != char:
                    return False
        if len(stack) != 0:
            return False
        return True
