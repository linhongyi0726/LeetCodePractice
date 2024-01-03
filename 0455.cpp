// First time
/*
    sort + 2 ptr
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j])
                i++;
            j++;
        }
        return i;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0, n = g.size(), m = s.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && g[i] > s[j])
                j++;
            if (j == m) {
                break;
            } else {
                j++;
                ret++;
            }
        }
        return ret;
    }
};