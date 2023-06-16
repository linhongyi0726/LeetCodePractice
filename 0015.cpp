// Second time
/*
    sort -> choose one number be target -> 2 sum
    nums[i] + nums[j] + nums[k] = 0
    nums[j] + nums[k] = -nums[i]
    
    *Notice when we move l and r to pass duplicated number,
    if do l++ and r-- first, we should compare pervious number we already moved
    and "l<r" need to be first of while loop condition for l ptr to avoid overflow in nums array

    T: O(nlogn + n^2)/S: O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=nums.size()-1;
            while (l<r) {
                if (nums[l]+nums[r] > -nums[i]) r--;
                else if (nums[l]+nums[r] < -nums[i]) l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    l++; r--;
                    /*
                    l++; r--;
                    while (l<r && nums[l]==nums[l-1]) l++;
                    while (l<r && nums[r]==nums[r+1]) r--;
                    */
                }
            }
        }
        return ans;
    }
};


// First time
/*
    sort to let x<y<z
    x+y+z=0
    -x=y+z
    Because x is the minimum of triplet, x definitely is negative
    Here it wil become 2 sum problem and target is -x (must positive),
    and can use 2 ptr to solve
    T: O(nlogn)+O(n^2) -> sort + 2 ptr for 2 sum
    S: O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i !=0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while (r > l) {
                if (nums[l]+nums[r] > -nums[i]) --r;
                else if (nums[l]+nums[r] < -nums[i]) ++l;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (r>l && nums[l] == nums[++l]);
                    while (r>l && nums[r] == nums[--r]);
                }
            }
        }
        return ans;
    }
};