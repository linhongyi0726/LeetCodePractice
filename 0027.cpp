// Second time
/*
    Use l to return because when we break loop, l will greater then r
    (r will stay at the first val element index-1)
    [3, 2, 2, 3] -> [2, 2, 3, 3], val = 3
                        ^  ^
                        r  l
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0, r=nums.size()-1;
        for (; l<=r; ++l) {
            if (nums[l]==val) {
                swap(nums[l--], nums[r--]);
            }
        }
        return l;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0, r=nums.size()-1;
        while (l<r) {
            if (nums[l]==val) swap(nums[l], nums[r--]);
            else l++;
        }
        return l+1;
    }
};

/*
    at the case val=3
    [3, 2, 2, 3] -> [2, 3, 2, 3] -> [2, 2, 3, 3]
     ^  ^               ^  ^               ^  ^
     l  r               l  r               l  r
    Move forward to check elements, l denote the non-val element we already checked
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[r]!=val) swap(nums[l++], nums[r]);
        }
        return l;
    }
};


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