// First time
/*
    Find the max and min of sub-array, then use (mx-mn)/(size-1) to calculate the diff
    If the array is arithmetic, the difference between every elements in the array and mn must be times of this diff
    And use (nums[j]-mn)/diff can calculate the position of this element should be,
    we can use an array to ensure every index has only one element

    T: O(m*n)/S: O(n)
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;
        for (int i = 0, j = 0; i < l.size(); ++i) {
            int mn = INT_MAX, mx = INT_MIN;
            for (int j = l[i]; j <= r[i]; ++j) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }
            int size = r[i] - l[i] + 1, diff = (mx - mn) / (size - 1);
            if (mx == mn) {
                ret.push_back(true);
            } else if ((mx - mn) % (size - 1)) {
                ret.push_back(false);
            } else {
                vector<bool> position(size, false);
                for (j = l[i]; j <= r[i]; ++j) {
                    int idx = (nums[j] - mn) / diff;
                    if ((nums[j] - mn) % diff || position[idx])
                        break;
                    position[idx] = true;
                }
                if (j > r[i])
                    ret.push_back(true);
                else
                    ret.push_back(false);
            }
        }
        return ret;
    }
};

/*
    Sort from the start to end of the sub-array,
    then check it is arithmetic or not

    T: O(m*nlogn)/S: O(n)
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;
        for (int i = 0; i < l.size(); ++i) {
            // Because of 0 <= l[i] < r[i] < n, the sub-array size must be 2 at last
            /*
            if (r[i] - l[i] <= 1) {
                ret.push_back(true);
                continue;
            }
            */
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(tmp.begin(), tmp.end());
            int j = 2;
            for (; j < tmp.size(); ++j) {
                if (tmp[j] - tmp[j - 1] != tmp[1] - tmp[0])
                    break;
            }
            if (j != tmp.size())
                ret.push_back(false);
            else
                ret.push_back(true);
        }
        return ret;
    }
};