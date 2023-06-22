// First time
/*
    0/1 knapsack
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0) return false;
        else sum/=2;
        vector<bool> dp(sum+1, false);
        dp[0]=true;
        for (int num:nums) {
            for (int i=sum; i>=num; --i) {
                dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[sum];
    }
};

/*
    bs[n] means we can get the sum n whether or not
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0) return false;
        else sum/=2;
        bitset<10001> bs;
        bs[0]=1;
        for (int num:nums) {
            bs|=(bs<<num);
        }
        return bs[sum];
    }
};