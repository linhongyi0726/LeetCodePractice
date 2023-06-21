// Third time
/*
    Use build-in STL function
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        return is_permutation(s.begin(), s.end(), t.begin()) && is_permutation(t.begin(), t.end(), s.begin());
    }
};

// Second time
/*
    Sort and compare
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

/*
    Use hash map to count every char -> also suitable for Unicode input
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp_s, mp_t;
        if (s.length()!=t.length()) return false;
        for (int i=0; i<s.length(); ++i) {
            mp_s[s[i]]++;
            mp_t[t[i]]++;
        }
        return mp_s==mp_t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if (s.length()!=t.length()) return false;
        for (char c:s) mp[c]++;
        for (char c:t) {
            if (!mp.count(c)) return false;
            mp[c]--;
            if(!mp[c]) mp.erase(c);
        }
        return mp.empty();
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if (s.length()!=t.length()) return false;
        for (char c:s) mp[c]++;
        for (char c:t) {
            if (!mp[c]) return false;
            mp[c]--;
        }
        return true;
    }
};

/*
    Use vector instead of hash map -> If input only consist of lowercase English letters
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        if (s.length()!=t.length()) return false;
        for (char c:s) v[c-'a']++;
        for (char c:t) {
            if (!v[c-'a']) return false;
            v[c-'a']--;
        }
        return true;
    }
};


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
    T: O(n)/S: O(1)
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