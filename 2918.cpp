// First time
/*
    Count 0 and check if all zero be replaced to at least 1 can satisfy or not
    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for (int num : nums1) {
            sum1 += num;
            if (num == 0)
                zero1++;
        }
        for (int num : nums2) {
            sum2 += num;
            if (num == 0)
                zero2++;
        }
        if (zero1 == 0 && zero2 == 0)
            return sum1 == sum2 ? sum1 : -1;
        else if (zero1 == 0)
            return sum2 + zero2 > sum1 ? -1 : sum1;
        else if (zero2 == 0)
            return sum1 + zero1 > sum2 ? -1 : sum2;
        else
            return max(sum1 + zero1, sum2 + zero2);
        /*
        if ((zero1 == 0 && sum2 + zero2 > sum1) || (zero2 == 0 && sum1 + zero1 > sum2))
            return -1;
        return max(sum1 + zero1, sum2 + zero2);
        */
    }
};