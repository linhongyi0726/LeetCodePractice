// Second time
/*
    If the num can be negative -> Problem 862
    ------
    2 ptr
    T: O(n)/S: O(1)
    ------
    prefix sum + binary search
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, ans=INT_MAX, l=0, r=0;
        for (; r<nums.size(); ++r) {
            sum+=nums[r];
            while (sum >= target) {
                ans=min(ans, r-l+1);
                sum-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        partial_sum(nums.begin()+1, nums.end(), nums.begin()+1);
        int ans=INT_MAX, n=nums.size();
        for (int l=0; l<n; ++l) {
            int r=lower_bound(nums.begin()+l, nums.end(), nums[l]+target)-nums.begin();
            if (r!=n) ans=min(ans, r-l);
        }
        return ans==INT_MAX?0:ans;
    }
};


// First time
/*
    Sliding windows
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, sum=0, ans=INT_MAX;
        for (int r=0; r<nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r-l+1);
                sum -= nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

/*
    Follow up:
    O(nlogn) solution -> binary search
*/
/*
    prefix sum + binary search
    ex.
       [2, 3, 1, 2,  4,  3], target=7
    [0, 2, 5, 6, 8, 12, 15] -> prefix sum
     ^        ^  ^      ^
     i        l  m      r   -> 8-0>=7

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        nums.insert(nums.begin(), 0);
        // partial_sum(nums.begin()+1, nums.end(), nums.begin()+1);
        for (int i=1; i<nums.size(); ++i) nums[i] += nums[i-1];
        // Choose left boundary to binary search right boundary
        for (int i=0; i<nums.size(); ++i) {
            int l=i+1, r=nums.size()-1;
            while (l <= r) {
                int m = l+(r-l)/2;
                if (nums[m]-nums[i] >= target) {
                    ans = min(ans, m-i);
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        nums.insert(nums.begin(), 0);
        // Choose right boundary to binary search left boundary, can do prefix sum at the same time
        for (int i=1; i<nums.size(); ++i) {
            nums[i] += nums[i-1];
            int l=0, r=i-1;
            while (l <= r) {
                int m = l+(r-l)/2;
                if (nums[i]-nums[m] >= target) {
                    ans = min(ans, i-m);
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

/*
    Different size of sub-array + binary search
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=nums.size(), ans=0;
        while (l <= r) {
            int m = l+(r-l)/2, i = 0, sum = 0;
            bool find = false;
            // Use selected size to find
            for (int j=0; j<nums.size(); ++j) {
                sum += nums[j];
                if (j-i+1 == m) {
                    if (sum >= target) {find = true; break;}
                    else sum -= nums[i++];
                }
            }
            if (find) {r = m-1; ans = m;}
            else l = m+1;
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX, sum=0;
        for (int i=0; i<nums.size(); ++i) {
            sum = 0;
            for (int j=i; j<nums.size(); ++j) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j-i+1); 
                    break;
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};