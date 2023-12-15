// First time
/*
    Hash set
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto path : paths)
            s.insert(path[0]);
        for (auto path : paths) {
            if (!s.count(path[1]))
                return path[1];
        }
        return "";
    }
};

/*
    Hash map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for (auto path : paths)
            mp[path[0]]++;
        for (auto path : paths) {
            if (!mp.count(path[1]))
                return path[1];
        }
        return "";
    }
};

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for (auto path : paths) {
            mp[path[0]]--;
            mp[path[1]]++;
        }
        for (auto it : mp) {
            if (it.second > 0)
                return it.first;
        }
        return "";
    }
};