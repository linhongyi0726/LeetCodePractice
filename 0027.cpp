// First time
/*
    move all non-val element to the front
    or move all val element to the behind
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[r] != val) nums[l++] = nums[r];
            // if (nums[r] != val) swap(nums[l++], nums[r]);
        }
        return l;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r=nums.size()-1;
        int l=-1;
        while (++l <= r) {
            if (nums[l] == val) swap(nums[l--], nums[r--]);
        }
        return l;
    }
};

/*
    remove() will remove all val in vector and won't change the size of vector
    it will return the next iterator of non-val
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return remove(nums.begin(), nums.end(), val)-nums.begin();
    }
};