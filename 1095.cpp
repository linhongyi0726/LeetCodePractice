// First time
/*
    The mountain array must have one peak, so binary search to find the peak
    then do two more times to find the target
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1, m = 0;
        // find the peak
        while (l < r) {
            m = l + (r - l) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1))
                l = m + 1;
            else
                r = m;
        }
        int peak = l, num = 0;
        l = 0;
        r = peak;
        // increasing
        while (l <= r) {
            m = l + (r - l) / 2;
            num = mountainArr.get(m);
            if (num == target)
                return m;
            else if (num > target)
                r = m - 1;
            else
                l = m + 1;
        }
        l = peak;
        r = n - 1;
        // decreasing
        while (l <= r) {
            m = l + (r - l) / 2;
            num = mountainArr.get(m);
            if (num == target)
                return m;
            else if (num > target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */