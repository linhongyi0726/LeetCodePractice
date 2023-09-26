// First time
/*
    If k > 1, the result must be sorted string s,
    because we can choose related large character to move
    If k = 1, just split the string and combine in each index to rotate
    ex. "cba"
    i=1: "c|ba" -> ba + c
    i=2: "cb|a" -> a + cb

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string ret = s;
        for (int i = 1; i < s.length(); ++i) {
            ret = min(ret, s.substr(i) + s.substr(0, i));
        }
        return ret;
    }
};