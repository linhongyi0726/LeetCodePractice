// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0, n=nums.size();
        for (int i=0; i<n; ++i) {
            if (n%(i+1)==0) ans+=pow(nums[i], 2);
        }
        return ans;
    }
};