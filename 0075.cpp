// Second time
/*
    one-pass algorithm
    Every element traversed by i is 1 or 0, so don't need i-- to go back
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        for (int i=0; i<=r; ++i) {
            if (nums[i]==0) swap(nums[i], nums[l++]);
            else if (nums[i]==2) swap(nums[i--], nums[r--]);
        }
    }
};


// First time
/*
    one-pass algorithm -> use two pointers
    l: "the largest index of 0" + 1
    r: "the smallest index of 2" - 1
    *Notice the for loop i <= r

    T: O(n)/S: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        for (int i=0; i<=r; ++i) {
            if (nums[i]==0) swap(nums[i], nums[l++]);
            else if (nums[i]==2) swap(nums[i--], nums[r--]);
        }
    }
};

/*
    Quick sort
    T: O(nlogn)/S: (1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {

    }
};

/*
    Bubble sort
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-1-i; ++j) {
                if (nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
};