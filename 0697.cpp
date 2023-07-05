// First time
/*
    Use two hash map to store number's count and number's first index
    * i means the last index of degree number

    We only need to traverse the vector one time and do the operations below
    1. store the first index
    2. count number's count
    3. update degree and ans (minium len of sub array)

    * Note even the count of number is equal to the degree,
    maybe there is another shorter sub array
    ex. [1,2,2,1,2,1,1,1,1,2,2,2] -> '1' and '2' have the same count 6
    '1' is the degree [1,2,2,1,2,1,1,1,1] -> len: 9
    '2' is the degree [2,2,1,2,1,1,1,1,2,2,2] -> len: 11

    T: O(n)/S:O(n)
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first;
        int ans = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!first.count(nums[i])) first[nums[i]] = i;
            count[nums[i]]++;
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                ans = i - first[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }
        return ans;
    }
};