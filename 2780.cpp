// First time
/*
    Without hash map to reduce space complexity
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom=nums[0], maxfreq=0;
        // find dominant element
        for (int num:nums) {
            if (num == dom) maxfreq++;
            else maxfreq--;
            if (maxfreq==0) {
                dom=num;
                maxfreq=1;
            }
        }
        // find dominant element frequency
        maxfreq=0;
        for (int num:nums) {
            if (num == dom) maxfreq++;
        }
        // choose minium sub-array which has the same dominant element
        int freq=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == dom) freq++;
            if (2*freq>i+1 && 2*(maxfreq-freq)>nums.size()-i-1) return i;
        }
        return -1;
    }
};

/*
    Use hash map to count the dominant element and each frequency
    *The whole array's dominant element must be two sub-array's dominant element
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dom=0, freq=0;
        for (int num:nums) mp[num]++;
        // Find dominant element and each frequency
        for (auto it:mp) {
            if (it.second>freq) {
                dom=it.first;
                freq=it.second;
            }
        }
        // Find sub-array (optimize below two for loop)
        freq=0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == dom) freq++;
            if (2*freq>i+1 && 2*(mp[dom]-freq)>nums.size()-i-1) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dom=0, freq=0;
        for (int num:nums) mp[num]++;
        for (auto it:mp) {
            if (it.second>freq) {
                dom=it.first;
                freq=it.second;
            }
        }
        int i=0;
        freq=0;
        for (;i<nums.size(); ++i) {
            if (nums[i] == dom) {
                freq++;
                if (2*freq>i+1) break;
            }
        }
        int ans=i;
        freq=0;
        for (int j=i+1;j<nums.size();++j) {
            if (nums[j]==dom) freq++;
        }
        if (2*freq<=nums.size()-i-1) return -1;
        return ans;
    }
};