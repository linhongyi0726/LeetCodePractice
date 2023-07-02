// First time
/*
    Sliding window
    T: O(n)/ S:O(1)
*/
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0, l=0, r=0;
        while (r<nums.size()) {
            if (r>0 && ((nums[r]%2 == nums[r-1]%2) || nums[r]>threshold)) l=r;
            if (nums[l]%2!=0 || nums[l]>threshold) l++;
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

/*
    Brute Force
    T: O(n^2)/S: O(1)
*/

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]%2==0 && nums[i]<=threshold && ans==0) ans++;
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i]%2==0 && (nums[j]%2 != nums[j-1]%2) && nums[i]<=threshold && nums[j]<=threshold) {
                    ans=max(ans, j-i+1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};