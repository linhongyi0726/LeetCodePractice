// First time
/*
    Similar with problem 169
    Boyer–Moore majority vote algorithm
    *Note because we want to find the element which count > n/3
    -> It will have at most two answers (1/3*2 < 1), so maintain two candidates of majority

    Also need to notice the order of if condition,
    we should update the majority candidate first,
    instead of checking the count first to avoid having the same candidates
    e.g.
    If check the count first:
         [2, 1, 1, 3, 1]
    maj1: 2        ^  1 -> the same candidates!
                cnt1=0
    maj2:    1

    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), maj1 = 0, maj2 = 0, cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == maj1) {
                cnt1++;
            } else if (num == maj2) {
                cnt2++;
            } else if (cnt1 == 0) {
                maj1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                maj2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == maj1)
                cnt1++;
            else if (num == maj2)
                cnt2++;
        }
        // check the candidate is answer or not
        vector<int> ret;
        if (cnt1 > n / 3)
            ret.push_back(maj1);
        if (cnt2 > n / 3 && maj1 != maj2)
            ret.push_back(maj2);
        return ret;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<int> ret;
        int n = nums.size();
        for (int num : nums)
            cnt[num]++;
        for (auto &it : cnt) {
            if (it.second > n / 3)
                ret.push_back(it.first);
        }
        return ret;
    }
};