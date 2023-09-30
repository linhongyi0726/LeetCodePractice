// First time
/*
    We want to find subsequence num1 < num3 < num2, call 132 pattern
    Track from the end, because it's more convenient to check "32" pair than "13" pair (have "2" to consider)
    Use monotonic stack to keep the possible "3"

    To every new number we encounter,
    First check is it can be "1" (< "2"), if yes -> return true
    if not, means it can be one of possible "3" (>= "2"), so we need to put it in stack.
    But to maintain the monotonicity (decreasing), need to check the top() of stack,
    ensure the new number is the smallest number in the stack,
    and the popped number can be new "2" -> it is smaller than all "3"
    ex.
    [6, 8, 7, 9, 10], stack: [], "2": null
                  ^
              "1" or "3" -> be "3"

    [6, 8, 7, 9, 10], stack: [10], "2": null
              ^
         "1" or "3" -> be "3" because haven't found possible "2", directly push to stack

    [6, 8, 7, 9, 10], stack: [10, 9], "2": null
           ^
        "1" or "3" -> be "3" because haven't found possible "2", directly push to stack

    [6, 8, 7, 9, 10], stack: [10, 9, 7], "2": null
        ^
    "1" or "3" -> be "3" because haven't found possible "2", pop 7 before pushing to stack

    [6, 8, 7, 9, 10], stack: [10, 9, 8], "2": 7
     ^
    "1" or "3" -> be "1" because 6 < 7 -> true

    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num2 = INT_MIN;
        stack<int> num3;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < num2)
                return true;
            // Ensure all numbers in stack num3 are greater than num2
            // pop smallest number one by one
            while (!num3.empty() && nums[i] > num3.top()) {
                num2 = num3.top();
                num3.pop();
            }
            // Let new element be part of num3
            num3.push(nums[i]);
        }
        return false;
    }
};

/*
    1 pass:
    Creat a vector to record the minimum of [0...i]
    -> It can be "1", because we want "1" be the smallest to easier form 132 pattern
    2 pass:
    Use ordered set to record the possible "2",
    (because in 132 pattern, "2" is the last element, we need to record form the end)
    then binary search to find "3" that can be 132 pattern
    ex.
    [6, 8, 9, 7], set: [] -> no possible "2" can pair with 7 ("3"),
              ^             so put 7 in the set to be possible "2"
             "3"
    [6, 8, 9, 7], set: [7] -> BS find end(), then check previous iterator 7 ("2")
           ^                  which can pair with 9 ("3") -> true
          "3"
    p.s. If BS find begin(), means the elements in set (possible "2") are all bigger than "3"
         -> can't be a "32" pair

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mn;
        int cur = INT_MAX;
        // minimum in nums[0...i]
        for (int num : nums) {
            cur = min(cur, num);
            mn.push_back(cur);
        }
        set<int> s;
        for (int i = nums.size() - 1; i >= 1; --i) {
            if (!s.empty()) {
                auto it = s.lower_bound(nums[i]);
                if (it != s.begin()) {
                    it = prev(it);
                    if (*it > mn[i] && nums[i] > *it)
                        return true;
                }
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

// insert finding "3" in set first will not change the result,
// but the logic doesn't make sense
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mn;
        int cur = INT_MAX;
        // minimum in nums[0...i]
        for (int num : nums) {
            cur = min(cur, num);
            mn.push_back(cur);
        }
        set<int> s;
        for (int i = nums.size() - 1; i >= 1; --i) {
            s.insert(nums[i]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.begin()) {
                it = prev(it);
                if (*it > mn[i] && nums[i] > *it)
                    return true;
            }
        }
        return false;
    }
};