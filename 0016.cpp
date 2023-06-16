// First time
/*
    Similar with problem 15: 3 Sum, just add diff to judge
    T: O(nlogn + n^2)/S: O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            int l=i+1, r=nums.size()-1;
            while (l<r) {
                int sum = nums[l]+nums[r]+nums[i];
                if (abs(target-sum)<abs(diff)) diff = sum-target;
                if (sum>target) r--;
                else if (sum<target) l++;
                else return sum;
            }
        }
        return target+diff;
    }
};