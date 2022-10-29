// First time
/*
    Quick sort
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {

    }
};

/*
    Bubble sort
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j > 0; --j) {
                if (nums[j] >= nums[j-1]) break;
                swap(nums[j], nums[j-1]);
            }
        }
    }
};