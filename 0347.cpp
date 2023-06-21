// First time
/*
    top Kth -> heap!!
    Use map to store frequency:number -> push to heap from hash map -> push to vector from heap
*/
/*
    max heap
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int n:nums) mp[n]++;
        for (auto it:mp) pq.push({it.second, it.first});
        for (int i=0; i<k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

/*
    min heap
    T: O(nlogk)/S: O(k) -> only use k size
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        for (int n:nums) mp[n]++;
        for (auto it:mp) {
            pq.push({it.second, it.first});
            if (pq.size()>k) pq.pop();
        }
        // while (!pq.empty())
        for (int i=0; i<k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};