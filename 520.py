class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() or word.islower():
            return True
        elif word[0].isupper():
            return word[1:].islower()
        else:
            return False


class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() or word.islower() or word.istitle():
            return True
        else:
            return False


class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 1:
            return True
        elif word[1:].islower() or word.isupper():
            return True
        else:
            return False
