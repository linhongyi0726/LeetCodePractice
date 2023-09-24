// First time
/*
    Move '1' to the front, than move one '1' to the end to make it odd
    2 ptr
    T:O(n)/S: O(1)
    -----
    sort
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length(), l = 0, r = 0;
        for (; r < n; ++r) {
            if (s[r] == '1')
                swap(s[l++], s[r]);
        }
        swap(s[l - 1], s[n - 1]);
        return s;
    }
};

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end(), greater());
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                swap(s[i - 1], s[n - 1]);
                break;
            }
        }
        return s;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1')
                cnt++;
        }
        string ret = "";
        for (int i = 0; i < s.length() - 1; ++i) {
            if (i < cnt - 1)
                ret += "1";
            else
                ret += "0";
        }
        return ret + "1";
    }
};