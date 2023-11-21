// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), ret = 0, m = 0, p = 0, g = 0;
        travel.insert(travel.begin(), 0);
        for (int i = 0; i < n; ++i) {
            ret += garbage[i].size();
            for (char c : garbage[i]) {
                if (c == 'M') {
                    m = i;
                } else if (c == 'P') {
                    p = i;
                } else {
                    g = i;
                }
            }
            if (i > 0)
                travel[i] += travel[i - 1];
        }
        ret += travel[m] + travel[p] + travel[g];
        return ret;
    }
};

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), ret = 0, m = 0, p = 0, g = 0;
        for (int i = 0; i < n; ++i) {
            ret += garbage[i].size();
            for (char c : garbage[i]) {
                if (c == 'M') {
                    m = i;
                } else if (c == 'P') {
                    p = i;
                } else {
                    g = i;
                }
            }
            if (i > 0 && i < n - 1)
                travel[i] += travel[i - 1];
        }
        if (m > 0)
            ret += travel[m - 1];
        if (p > 0)
            ret += travel[p - 1];
        if (g > 0)
            ret += travel[g - 1];
        return ret;
    }
};