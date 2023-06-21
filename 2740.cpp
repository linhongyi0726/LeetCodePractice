// First time
/*
    Sort and find the minium interval
    T:O(n)/S: O(1)
*/
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for (int i=1; i<nums.size(); ++i) ans=min(ans, nums[i]-nums[i-1]);
        return ans;
    }
};

/*
    two pointer
    move form left and right, and compare where interval is larger
    T:O(n)/S: O(1)
*/
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0, r=nums.size()-1;
        int ans=INT_MAX;
        while(l<r) {
            if(nums[r]-nums[l]<ans) ans=nums[r]-nums[l];
            else {
                if(nums[l+1]-nums[l] > nums[r]-nums[r-1]) l++;
                else r--;
            }
        }
        return ans;
    }
};