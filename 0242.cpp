// First time
/*
    1.
    Use hash map to store every alphabets and its count
    Then traverse another string and decrease 1 if we found the same alphabets
    Or we can make two map to store each string, then compare them
    T: O(n)/S: O(n)
    2.
    Because s and t only consist of lowercase English letters
    -> We can only use a vector to store all 26 letters' counts
    T: O(n)/S :O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char,int> mp;
        for (int i = 0; i < s.size(); ++i)
            mp[s[i]]++;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(t[i])) {
                mp[t[i]]--;
                if (mp[t[i]] == 0)
                    mp.erase(t[i]);
            }
            else
                return false;
        }

        return mp.empty();
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for (char c : s)
            v[c-'a']++;
        for (char c : t) {
            v[c-'a']--;
        }
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            if (*it)
                return false;
        }
        return true;
    }
};