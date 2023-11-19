// First time
/*
    Find the longest equal string from left
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        int n = min(len1, min(len2, len3)), i = 0;
        for (; i < n; ++i) {
            if (s1[i] != s2[i] || s2[i] != s3[i] || s1[i] != s3[i])
                break;
        }
        if (i == 0)
            return -1;
        return len1 - i + len2 - i + len3 - i;
    }
};