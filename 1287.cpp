// First time
/*
    Binary search
    Because it's guaranteed that only one number will appear more than 25% times,
    and this number will definitely at one of those positions: 25%, 50%, 75%
    So we can do binary search to check those three numbers

    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> cand = {arr[n / 4], arr[n / 2], arr[n * 3 / 4]};
        for (int c : cand) {
            int idx = lower_bound(arr.begin(), arr.end(), c) - arr.begin();
            if (arr[idx + n / 4] == c)
                return c;
        }
        return -1;
    }
};

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> cand = {arr[n / 4], arr[n / 2], arr[n * 3 / 4]};
        for (int c : cand) {
            auto lb = lower_bound(arr.begin(), arr.end(), c);
            auto ub = upper_bound(arr.begin(), arr.end(), c);
            if (ub - lb > n / 4)
                return c;
        }
        return -1;
    }
};

/*
    Sliding window
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), n25 = n / 4;
        for (int i = 0; i < n - n25; ++i) {
            if (arr[i] == arr[i + n25])
                return arr[i];
        }
        return -1;
    }
};

/*
    2 ptr
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), l = 0;
        for (int r = 0; r < n; ++r) {
            if (arr[r] != arr[l]) {
                if (r - l > n / 4)
                    return arr[l];
                l = r;
            }
        }
        return arr[n - 1];
    }
};