// Second time
/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1;
        vector<int> ans(n, 0);
        while (l<=r) {
            if (abs(nums[l])>abs(nums[r])) ans[--n]=pow(nums[l++], 2);
            else ans[--n]=pow(nums[r--], 2);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1;
        vector<int> ans(n, 0);
        while (l<=r) {
            ans[--n] = abs(nums[l])>abs(nums[r]) ? pow(nums[l++], 2) : pow(nums[r--], 2);
        }
        return ans;
    }
};


// First time
/*
    Follow up: O(n) time complexity
    Use 2 ptr and the other array
    p.s. we can't swap element in-place because it will destroy the order

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1;
        vector<int> ans(n, 0);
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) ans[--n] = pow(nums[l++], 2);
            else ans[--n] = pow(nums[r--], 2);
        }
        return ans;
    }
};
/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int &num:nums) num = pow(num, 2);
        sort(nums.begin(), nums.end());
        return nums;
    }
};