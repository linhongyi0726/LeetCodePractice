// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, cnt=0;
        for (int num:nums) {
            if (num==1) {
                cnt++;
            } else {
                ans=max(ans, cnt);
                cnt=0;
            }
        }
        return max(ans, cnt);
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, cnt=0;
        for (int num:nums) {
            if (num==1) {
                cnt++;
                ans=max(ans, cnt);
            } else {
                cnt=0;
            }
        }
        return ans;
    }
};