// First time
/*
    Use map to record the frequency of each numbers
    We want to find the longest sub-array
    -> find the maximum frequency of elements, and it can create a sub-array
    Here "ans" denote the maximum frequency of elements in whole array not only the sub-array

    Our windows size will not be decreased, and will continually move until we find another larger "ans"
    -> means find larger frequency of elements
    [1, 3, 2, 3, 1, 3, 2], k=3
     ^                 ^
     l                 r -> max freq number for now: 3, r-l+1-3=4 -> the elements needed to delete > 3
        l -> need to move l, and --cnt[1]
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans=0, l=0, r=0;
        for (; r<nums.size(); ++r) {
            ans=max(ans, ++cnt[nums[r]]);
            if (r-l+1-ans > k) --cnt[nums[l++]];
        }
        return ans;
    }
};

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int tmp=0, ans=0, l=0, r=0;
        for (; r<nums.size(); ++r) {
            tmp=max(tmp, ++cnt[nums[r]]);
            if (r-l+1-tmp > k) --cnt[nums[l++]];
            ans=max(ans, tmp);  // Or we can just return tmp
        }
        return ans;
    }
};

/*
    Use map to record every index of each number in nums
    Then sliding window to scan max sub-array
    T: O(n)/ S:O(n)
*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int ans=1;
        for (int i=0; i<nums.size(); ++i) mp[nums[i]].push_back(i);
        for (auto it:mp) {
            int l=0, r=1, cnt=k;
            // Sliding window
            for (; r<it.second.size(); ++r) {
                cnt-=it.second[r]-it.second[r-1]-1;
                while (cnt<0) {
                    cnt+=it.second[l+1]-it.second[l]-1;
                    l++;
                }
                ans=max(ans, r-l+1);
            }
        }
        return ans;
    }
};

/*
    Brute-force -> TLE
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size(), l=0, r=0, ans=0, cnt=k, tmp=0;
        while (l<n) {
            cnt=k;
            tmp=0;
            for (r=l; r<n; ++r) {
                if (nums[r]!=nums[l]) {
                    if (cnt) cnt--;
                    else break;
                } else {
                    tmp++;
                }
            }
            ans=max(ans, tmp);
            l++;
        }
        return ans;
    }
};