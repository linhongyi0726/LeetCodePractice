// First time
/*
    time complexity should be O(log (m+n)) -> Binary search!!

    Just consider the index
    nums1:    0 ... m1-1, m1 ... n1-1
                      ^   ^
                   left1  right1
    nums2:    0 ... m2-1, m2 ... n2-1
                      ^   ^
                   left2  right2
    merge(v): 0 ... k-1, k ... n1+n2-1 -> odd: v[k], even: (v[k]+v[k-1])/2
             |_________|
               k = m1 + m2
    v[k-1] = max(nums1[m1-1], nums[m2-1])
    v[k] = min(nums1[m1], nums2[m2])

    Use binary search to guess m1
    ex.
    odd:  0, (1), 2    -> 3/2 = 1 = k
    even: 0, (1, 2), 3 -> 4/2 = 2 = k

    T: O(log(m+n))/S: O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int n1 = nums1.size(), n2 = nums2.size();
        int l = 0, r = n1;
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = (n1 + n2) / 2 - m1;

            int left1 = m1 == 0 ? INT_MIN : nums1[m1 - 1];
            int right1 = m1 == n1 ? INT_MAX : nums1[m1];
            int left2 = m2 == 0 ? INT_MIN : nums2[m2 - 1];
            int right2 = m2 == n2 ? INT_MAX : nums2[m2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1 + n2)&1)
                    return min(right1, right2);
                else
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if (right1 < left2)
                l = m1 + 1;
            else
                r = m1 - 1;
        }
        return 0.0;
    }
};