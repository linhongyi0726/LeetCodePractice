// Second time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), l=1, r=1;
        vector<int> ans(n,1);
        for (int i=0; i<n; ++i) {
            ans[i]*=l;
            ans[n-1-i]*=r;
            l*=nums[i];
            r*=nums[n-1-i];
        }
        return ans;
    }
};

// First time
/*
    1. Count the product of all number and divided each (Notice the zero)
        T: O(n)/S: O(1)
    2. Brute force without division
        T: O(n^2)/S: O(1)
    3. 2 pointer (prefix sum)
            ex.[1,  2,  3, 4]
    forward -> [1,  1,  2, 6]
               [24, 12, 4, 1] <- backward
            *)_______________
          ans: [24, 12, 8, 6]
                ^          ^
            not change    not change
        T: O(n)/S: O(n)
        ========================
        Follow up:
        Use int to replace forward and backward vector to reduce space complexity
        T: O(n)/S: O(1)

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> front(n, 1);
        vector<int> back(n, 1);
        for (int i = 1; i < n; ++i)
            front[i] = front[i-1] * nums[i-1];
        for (int i = n-2; i >=0; --i)
            back[i] = back[i+1] * nums[i+1];
        for (int i = 0; i < n; ++i)
            ans[i] = front[i] * back[i];
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = 1;
        vector<int> ans(n, 1);
        for (int i = 0; i < n ; ++i) {
            ans[i] *= l;
            l *= nums[i];
            ans[n-i-1] *= r; 
            r *= nums[n-i-1];
        }
        return ans;
    }
};