// First time
/*
    Because of the constraints of problem
    "All the timestamps timestamp of set are strictly increasing."
    we don't need to sort before binary search
*/
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key)) {
            int l = 0, r = mp[key].size()-1;
            while (l<=r) {
                int mid = (l+r)/2;
                if (timestamp == mp[key][mid].first) return mp[key][mid].second;
                else if (timestamp > mp[key][mid].first) l = mid+1;
                else r = mid-1;
            }
            return r>=0 ? mp[key][r].second : "";
            /*
            // Use STL upper_bound
                auto it = upper_bound(mp[key].begin(), mp[key].end(), timestamp, [](int val, auto& v){return val < v.first;});
                if (it != mp[key].begin()) {
                    return (--it)->second;
                }
            */
        }
        return "";
    }
};

/*
    Two map approach
    Because of "timestamp_prev <= timestamp", we use upper_bound instead of lower_bound
    Just need to choose previous iterator

    Unless we use greater<int> to sort the map descending, then we can use lower_bound
*/
class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    // unordered_map<string, map<int, string, greater<int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key)) {
            auto it = mp[key].upper_bound(timestamp);
            if (it != mp[key].begin()) return (--it)->second;
            /*
                auto it = mp[key].lower_bound(timestamp);
                if (it != mp[key].end()) return it->second;
            */
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */