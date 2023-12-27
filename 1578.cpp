// First time
/*
    the same idea, but only store the maximum of time,
    then add minimum time to "ret"

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0, n = colors.length(), mx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                mx = 0;
            }
            ret += min(neededTime[i], mx);
            mx = max(mx, neededTime[i]);
        }
        return ret;
    }
};

/*
    group the same character, then calculate the sum and the maximum needed time to remove,
    remain the max time character

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0, n = colors.length(), sum = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                ret += sum - mx;
                sum = 0;
                mx = 0;
            }
            sum += neededTime[i];
            mx = max(mx, neededTime[i]);
        }
        ret += sum - mx;
        return ret;
    }
};

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0, n = colors.length();
        for (int i = 1; i < n; ++i) {
            int sum = 0, mx = 0;
            while (i < n && colors[i] == colors[i - 1]) {
                sum += neededTime[i - 1];
                mx = max(mx, neededTime[i - 1]);
                i++;
            }
            sum += neededTime[i - 1];
            mx = max(mx, neededTime[i - 1]);
            ret += sum - mx;
        }
        return ret;
    }
};