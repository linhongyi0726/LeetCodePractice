// First time
/*
    Use two map to record the position and gap
    Notice to check rotate array, we can check 1 pass by the condition i<nums.size()*2

    2, 1, 3, 3, 2,|2, 1, 3, 3, 2
             ^___________^
          ^_________________^ -> use mod to get the correct distance, [2,8] just like [2,3]
    T: O(n)/ S:O(n)
*/
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, int> idx, gap;
        int n=nums.size(), ans=INT_MAX;
        for (int i=0; i<n; ++i) {
            if (idx.count(nums[i])) gap[nums[i]]=max(gap[nums[i]], i-idx[nums[i]]-1);
            idx[nums[i]]=i;
        }
        for (int i=0; i<n; ++i) {
            gap[nums[i]]=max(gap[nums[i]], ((i+n)-idx[nums[i]]-1)%n);
            idx[nums[i]]=i;
        }
        for (auto it:gap) ans=min(ans, it.second);
        return (ans+1)/2;
    }
};

// 1 pass
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, int> idx, gap;
        int n=nums.size(), ans=INT_MAX;
        for (int i=0; i<n*2; ++i) {
            int num=nums[i%n];
            if (idx.count(num)) gap[num]=max(gap[num], i-idx[num]-1);
            idx[num]=i;
        }
        for (auto it:gap) ans=min(ans, it.second);
        return (ans+1)/2;
    }
};

/*
    Use map to record the index of each number in nums
    *Add it.second[0]+n to simulate a gap between the first and last positions
    -> Let it become a circular array
    ex. Because it's circular array, only need 1 second to become equal
    [8, 13, 3, 3] 8, 13...
         ^__|  |__^
    index:
     0, 1,  2, 3,|4, 5, 6 => add index 6 to be last index, just like we move [0,1] to [4,5]
    |____|       |____|
       ------------^
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n=nums.size(), ans=INT_MAX;
        for (int i=0; i<n; ++i) mp[nums[i]].push_back(i);
        for (auto it:mp) {
            // Let it become a circular array
            it.second.push_back(it.second[0]+n);
            int sec=0;
            for (int i=1; i<it.second.size(); ++i) {
                sec=max(sec, (it.second[i]-it.second[i-1])/2);
            }
            ans=min(ans, sec);
        }
        return ans;
    }
};

// Count distance instead of seconds
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n=nums.size(), ans=INT_MAX;
        for (int i=0; i<n; ++i) mp[nums[i]].push_back(i);
        for (auto it:mp) {
            vector<int> v=it.second;
            int dist=(n-1-v[v.size()-1])+v[0];
            for (int i=1; i<v.size(); ++i) {
                dist=max(dist, v[i]-v[i-1]-1);
            }
            ans=min(ans, dist);
        }
        return (ans+1)/2;
    }
};