// First time
/*
    Use binary search
    * Notice overflow
    T: O(logn)/S: O(1)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m;
        while (l <= r) {
            m = l + (r-l)/2;
            if (isBadVersion(m))
                r = m-1;
            else
                l = m+1;
        }
        return l;
    }
};