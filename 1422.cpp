// First time
/*
    pre-calculate all amount of '1',
    then iterate the string to calculate the left and right substring
    *Notice only need to traverse to n-1, because there is at least one element in right substring

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxScore(string s) {
        int ret = 0, n = s.length();
        int cnt0 = 0, cnt1 = accumulate(s.begin(), s.end(), 0) - '0' * n;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0')
                cnt0++;
            if (s[i] == '1')
                cnt1--;
            ret = max(ret, cnt0 + cnt1);
        }
        return ret;
    }
};

/*
    Use prefix sum to pre-calculate the amount of '1'
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxScore(string s) {
        int ret = 0, n = s.length(), cnt = 0;
        vector<int> prefix(n, 0);
        prefix[n - 1] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; --i) {
            prefix[i] = prefix[i + 1] + s[i] - '0';
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0')
                cnt++;
            ret = max(ret, cnt + prefix[i + 1]);
        }
        return ret;
    }
};