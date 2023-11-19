// First time
/*
    Let the number become previous number + 1 or itself
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int pre = 0;
        for (int num : arr) {
            pre = min(pre + 1, num);
        }
        return pre;
    }
};