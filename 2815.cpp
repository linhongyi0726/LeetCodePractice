// First time
/*
    Use map to store the max digits of max numbers
    key: max digits, value: max numbers -> the maximum of map.size() is 9
    T: O(n*k)/S: O(1)
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size(), ans=-1;
        for (int num:nums) {
            int digits=0, tmp=num;
            while (tmp) {
                digits=max(digits, tmp%10);
                tmp/=10;
            }
            if (mp.count(digits)) ans=max(ans, mp[digits]+num);
            mp[digits]=max(mp[digits], num);
        }
        return ans;
    }
};

/*
    *Notice the problem request us to find two numbers which "max digits" is the same,
    and return the sum of two numbers
    **NOT need to find the sum of two numbers' digits is the same
    T: O(n^2*k)/S: O(1)
*/
class Solution {
public:
    bool check(int num1, int num2) {
        int max1=0, max2=0;
        while (num1) {
            max1=max(max1, num1%10);
            num1/=10;
        }
        while (num2) {
            max2=max(max2, num2%10);
            num2/=10;
        }
        return max1==max2;
    }
    int maxSum(vector<int>& nums) {
        // Here sorting may not help,
        // because the two "max valid numbers" sum not means the max sum
        // sort(nums.begin(), nums.end(), greater<int>());
        int n=nums.size(), ans=-1;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (check(nums[i], nums[j])) ans=max(ans, nums[i]+nums[j]);
            }
        }
        return ans;
    }
};