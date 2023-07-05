// First time
/*
    the possible positive number in nums are 1...n, then the biggest answer is n+1
    We can use index+1 to represent the positive number which is already in the nums
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l=0, r=nums.size();
        // Put negative number to the end
        while (l<r) {
            if (nums[l]<=0) swap(nums[l], nums[--r]);
            else l++;
        }
        // *Here r means the amount of positive number in nums
        // Use negative sign to mark the exist positive number (also equal to index+1)
        for (int i=0; i<r; ++i) {
            int num=abs(nums[i]);
            if (num>=1 && num<=r)
                nums[num-1] = -abs(nums[num-1]);
        }
        // Find missing number (not marked by negative sign)
        for (int i=0; i<r; ++i) {
            if (nums[i]>0) return i+1;
        }
        return r+1;
    }
};

/*
    Optimize:
    Put positive number which <= n to corresponding index
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=1;
        set<int> s(nums.begin(), nums.end());
        for (int n : s) {
            if (n > 0) {
                if (n != ans) return ans;
                else ans++;
            }
        }
        return ans;
    }
};