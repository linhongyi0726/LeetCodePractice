// First time
/*
    Two ptr
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1=0, p2=0, n1=nums1.size(), n2=nums2.size();
        while (p1<n1 && p2<n2) {
            if (nums1[p1] == nums2[p2]) {
                ans.push_back(nums1[p1]);
                // move p1 and p2 to the last the same element
                while (p1+1<n1 && nums1[p1] == nums1[p1+1]) p1++;
                while (p2+1<n2 && nums2[p2] == nums2[p2+1]) p2++;
                // move to the next different element
                p1++; p2++;
            } else if (nums1[p1] < nums2[p2]) {
                p1++;
            } else {
                p2++;
            }
        }
        return ans;
    }
};

/*
    Use hash set to record elements in nums
    also can use unordered_set<int> s(nums1.begin(), nums1.end())
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        for (int num1:nums1) s.insert(num1);
        for (int num2:nums2) {
            if (s.count(num2)) {
                ans.push_back(num2);
                s.erase(num2);
            }
        }
        return ans;
    }
};