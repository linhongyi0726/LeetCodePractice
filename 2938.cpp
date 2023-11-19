// First time
/*
    Count the number of '1' we visited so far,
    then if we meet '0', means we need to move all previous '1' to here
    -> ret += cnt

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length(), cnt = 0;
        long long ret = 0;
        for (char c : s) {
            if (c == '1')
                cnt++;
            else
                ret += cnt;
        }
        return ret;
    }
};

/*
    calculate the index difference between last and original
    -> we only can swap adjacent balls
    because '1' should be put behind, the index of first '1' is n-cnt
    e.g.
       "1 1 0 0 1"
         \ \    |
          \ \   |
           \ \  |
    -> "0 0 1 1 1"

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length(), cnt = 0;
        long long ret = 0;
        for (char c : s) {
            if (c == '1')
                cnt++;
        }
        int start = n - cnt;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ret += start - i;
                start++;
            }
        }
        return ret;
    }
};