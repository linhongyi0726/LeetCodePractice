// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0, cur = 0, pre = 0;
        for (auto s : bank) {
            cur = 0;
            for (char c : s) {
                if (c == '1')
                    cur++;
            }
            if (cur) {
                ret += cur * pre;
                pre = cur;
            }
        }
        return ret;
    }
};