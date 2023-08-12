// First time
/*
    Use one pass and hash set,
    here we don't need to check 0 case because we won't visit itself twice,
    but need to check num*2 and num/2 case
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        int n=arr.size();
        for (int num:arr) {
            if (s.count(num*2) || (s.count(num/2) && !(num&1))) return true;
            s.insert(num);
        }
        return false;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n=arr.size();
        for (int i=0; i<n; ++i) mp[arr[i]]=i;
        for (int i=0; i<n; ++i) {
            // Check index to avoid 0 case because 0=2*0 itself
            if (mp.count(arr[i]*2) && mp[arr[i]*2]!=i) return true;
        }
        return false;
    }
};