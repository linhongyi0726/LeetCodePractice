// First time
/*
    Majority means the element will appear more than n/2 times
    1. Use hash map to save times
        T: O(n)/S: O(n)
    2. Sort and return the middle number
        T: O(nlogn)/S: O(1)
    3. Boyer–Moore majority vote algorithm
        Discard "one of majority element" and "one of non-majority element" won't change the majority element
        
        Traverse the array and count element appear times
        Declare a variable "majority" to store majority element for now
        ```
        if majority == element -> count+1
        else count-1 (Discard majority element and non-majority element)
        and if count == 0, it means our majority isn't truly majority element, so update it
        ```
        At least, it will remain one element in the "majority" variable
        Because there is always a majority element in the array at these problem, so it's the answer
        (If not, we need to traverse second times to count the return element appear times to make sure it's majority element or not)

        Here we only traverse one time
        T: O(n)/S: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > nums.size()/2)
                return num;
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 0;
        for (int num : nums) {
            if (count == 0)
                maj = num;
            if (maj == num)
                ++count;
            else
                --count;
        }
        return maj;
    }
};

