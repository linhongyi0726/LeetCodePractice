// First time
/*
    *Similar with problem 41
    Use index+1 to represent the positive number,
    so mark the element to negative to represent the index+1 is already seen
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int num:nums) nums[abs(num)-1]=-abs(nums[abs(num)-1]);
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};

/*
    *Similar with problem 41
    Put element to corresponding index
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]!=nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};

/*
    Use other data structure (hash set, hash map, vector) to store the seen number
    *Notice the duplicate number
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<int> ans;
        for (int num:nums) count[num-1]++;
        for (int i=0; i<count.size(); ++i) {
            if (!count[i]) ans.push_back(i+1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        for (int i=1; i<=nums.size(); ++i) {
            if (!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};