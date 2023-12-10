// First time
/*
    Because every time we test, the remain batteries will be decreased by 1
    So just compare the times we test for now with current device battery,
    if the battery percentage is greater than the test times,
    it means we can test with this device, so ret++

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0;
        for (int n : batteryPercentages) {
            if (n > ret)
                ret++;
        }
        return ret;
    }
};

/*
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0, n = batteryPercentages.size();
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] > 0) {
                ret++;
                for (int j = i + 1; j < n; ++j) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return ret;
    }
};