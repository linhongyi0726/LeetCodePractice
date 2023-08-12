// First time
/*
    Use "pre" to keep last index of 0 which r visited
    T: O(n)/ S:O(1)
    ---
    Follow up:
    If we can flip k times, we can use queue to store every 0's index,
    then l=q.top()+1 to move to the smallest index+1 when q.size()>k
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0, r=0, ans=0, pre=-1;
        for (; r<nums.size(); ++r) {
            if (!nums[r]) {
                l=pre+1;
                pre=r;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};