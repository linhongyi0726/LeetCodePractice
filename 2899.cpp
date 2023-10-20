// First time
/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums, ret;
        int k = 0;
        for (string word : words) {
            if (word == "prev") {
                k++;
                if (k <= nums.size())
                    ret.push_back(*(nums.end() - k));
                else
                    ret.push_back(-1);
            } else {
                k = 0;
                nums.push_back(stoi(word));
            }
        }
        return ret;
    }
};