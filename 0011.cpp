// First time
/*
    To build the max area of water should have two conditions:
    1. the max of width
    2. the max of container (higher boundary)
    Choose the most left and right boundary to build the max width,
    then start to shrink the width
    -> only shrink the lower boundary side to maintain more higher boundary

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, ret = 0;
        while (l < r) {
            ret = max(ret, (r - l) * min(height[l], height[r]));
            if (height[r] > height[l])
                l++;
            else
                r--;
        }
        return ret;
    }
};