// Firs time
/*
    We have n+1 integers but only have n size array
    According of Pigeonhole Principle, there is must at least one duplicate number
    -----
    Sort the find the duplicate or Use sign bit to record the seen number
    But need to modify nums
    T: O(nlogn)/S: O(1)
    -----
    Use hash map to record the number
    T: O(n)/S: O(n)
    -----
    Use sign bit to record the seen number
    But need to modify nums
    ex.
    [1, 2, 2] -> [-1, 2, 2]     =>      [-1, 2, 2] -> [-1, -2, 2]
     ^                                       ^
    modify index (1-1) to negative         modify index (2-1) to negative
    T: O(n)/S: O(1)
    -----
    We can treat it a cyclic linked list,
    the address of node is index and the next node's address is the value
    ex.
 idx 0  1  2  3  4     0  1  3  2  4
    [1, 3, 4, 2, 2] => 1->3->2->4->2
                                ^__|
    Then use Floyd's Tortoise and Hare to find the start of cyclic
    first loop to find the meeting point of slow and first ptr
    second loop to find the start point of the cyclic
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        /*
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);
        */
        while (s != f || s == 0) {
            s = nums[s];
            f = nums[nums[f]];
        }
        s = 0;
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};

/*
    Because the answer is in [1,n], we can use binary search to guess the answer
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 1, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= m)
                    cnt++;
            }
            if (cnt > m)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

/*
    According to the value of element, move it to correct index
    Need to modify input
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == i + 1)
                continue;
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            } else {
                return nums[i];
            }
        }
        return 0;
    }
};