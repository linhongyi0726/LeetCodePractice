// First time
/*
    Sort + 2 ptr
    [4, 6, 1, 2], k = 2
    [1, 2, 4, 6]
    -> If the diff between max and min > 2*k, means that sub-array can't be "beauty"

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int l=0, r=0, ans=1;
        sort(nums.begin(), nums.end());
        for (;r<nums.size(); ++r) {
            if (nums[r]-nums[l]>2*k) ++l;
            else ans=max(ans, r-l+1);
        }
        return ans;
    }
};

/*
    Brute force -> TLE
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans=0, tmp=0, mn=INT_MAX, mx=INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            tmp=0; mn=nums[i]; mx=nums[i];
            for (int j=0; j<nums.size(); ++j) {
                if (abs(nums[j]-nums[i])<=2*k) {
                    mn=min(mn, nums[j]);
                    mx=max(mx, nums[j]);
                    ++tmp;
                }
                if (mx-mn>2*k) {
                    --tmp;
                    break;
                }
            }
            ans=max(ans, tmp);
        }
        return ans;
    }
};