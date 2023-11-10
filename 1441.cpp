// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int m = target.size(), j = 0;
        for (int i = 1; i <= n; ++i) {
            ret.push_back("Push");
            if (i == target[j])
                j++;
            else
                ret.push_back("Pop");
            if (j == m)
                break;
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int i = 1;
        for (int num : target) {
            while (i <= n && i != num) {
                ret.push_back("Push");
                ret.push_back("Pop");
                i++;
            }
            ret.push_back("Push");
            i++;
        }
        return ret;
    }
};