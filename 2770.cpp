// First time
/*
    dp[i] means the max steps jump to index i

    Accumulate the jumps step which index i can jump to
    [1, 3, 6, 4, 1, 2], target=2
     ^
        ^        ^  ^ -> index 0 can jump to those position
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            // dp[i]==-1 means we can't reach here
            if (dp[i] != -1) {
                for (int j=i+1; j<n; ++j) {
                    if (abs(nums[j]-nums[i]) <= target) {
                        dp[j] = max(dp[i]+1, dp[j]);
                    }
                }
            }
        }
        return dp[n-1];
    }
};

/*
    Go back and count the jump steps for reaching index j
    [1, 3, 6, 4, 1, 2], target=2
              ^
        ^  ^    -> those position can jump to index 3
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[0]=0;
        for (int j=1; j<n; ++j) {
            for (int i=j-1; i>=0; --i) {
                if (dp[i]!=-1 && abs(nums[j]-nums[i])<=target) {
                    dp[j]=max(dp[i]+1, dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};