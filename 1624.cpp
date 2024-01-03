// First time
/*
    one pass
    only store the first index of each character

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int n = s.length(), ret = -1;
        for (int i = 0; i < n; ++i) {
            if (mp.count(s[i]))
                ret = max(ret, i - mp[s[i]] - 1);
            else
                mp[s[i]] = i;
        }
        return ret;

    }
};

/*
    only store the last index of each character

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int n = s.length(), ret = -1;
        for (int i = 0; i < n; ++i) {
            mp[s[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            ret = max(ret, mp[s[i]] - i - 1);
        }
        return ret;
    }
};

/*
    store the first and the last index of each character

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, pair<int, int>> mp;
        int n = s.length(), ret = -1;
        for (int i = 0; i < n; ++i) {
            if (!mp.count(s[i]))
                mp[s[i]] = {i, i};
            else
                mp[s[i]].second = i;
        }
        for (auto [c, p] : mp) {
            ret = max(ret, p.second - p.first - 1);
        }
        return ret;

    }
};

/*
    store all the index of the same character,
    then calculate the difference between the first and the last

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.length(), ret = -1;
        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }
        for (auto [c, v] : mp) {
            ret = max(ret, v[v.size() - 1] - v[0] - 1);
        }
        return ret;

    }
};