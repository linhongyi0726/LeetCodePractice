// First time
/*
    move from the end of nums1, put the larger number to the end
    we need to merge nums2 to nums1, so just to judge n>0
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n) {
            int k = m+n-1;
            if (m && nums1[m-1] > nums2[n-1])
                nums1[k] = nums1[--m];
            else
                nums1[k] = nums2[--n];
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1; i >= 0; --i) {
            if (n > 0) {
                if (m > 0 && nums1[m-1] > nums2[n-1]) {
                    nums1[i] = nums1[m-1];
                    m--;
                } else {
                    nums1[i] = nums2[n-1];
                    n--;
                }
            }
        }
    }
};