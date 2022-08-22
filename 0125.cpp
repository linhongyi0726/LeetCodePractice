// First time
/*
    Use two pointer at the start and end position of the string to traverse it
    isalnum() can let us know this character is alphanumeric or not
    If it's alphanumeric, compare it and move toward/back
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (isalnum(s[start]) && isalnum(s[end])) {
                if (tolower(s[start]) == tolower(s[end])) {
                    start += 1;
                    end -= 1;
                    continue;
                } else
                    return false;
            } else if (!isalnum(s[start]))
                start += 1;
            else if (!isalnum(s[end]))
                end -= 1;
        }
        return true;
    }
};