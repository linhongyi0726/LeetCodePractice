// First time
/*
    Binary search
    return l when we end loop because we want the bigger index (l>r)
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<=r) {
            int m=l+(r-l)/2;
            if (nums[m]==target) return m;
            else if (nums[m]>target) r=m-1;
            else l=m+1;
        }
        return l;
    }
};