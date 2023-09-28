// Second time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if ((nums[r]&1) == 0)
                swap(nums[l++], nums[r]);
        }
        return nums;
    }
};


// First time
/*
    2 ptr
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0, r=0;
        for (; r<nums.size(); ++r) {
            if (!(nums[r]&1)) swap(nums[l++], nums[r]);
        }
        return nums;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return (a&1)<(b&1);
        });
        return nums;
    }
};