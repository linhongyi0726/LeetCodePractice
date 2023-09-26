// First time
/*
    Use XOR, just like RAID
    s: [5, 1, 2]    -> 5^1^2 = 6
    t: [5, 1, 3, 2] -> 6^5^1^3^2 = 3

    T: O(n)/S: O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        for (char c : s)
            ret ^= c;
        for (char c : t)
            ret ^= c;
        return ret;
    }
};

/*
    Calculate the diff of sum of s and t,
    but store the diff result at next element
    T: O(n)/S: O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < t.length() - 1; ++i)
           t[i + 1] += t[i] - s[i];
        return t[t.length() - 1];
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : t) {
            if (mp[c] == 0)
                return c;
            mp[c]--;
        }
        return 0;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < t.length(); ++i) {
            if (s[i] != t[i])
                return t[i];
        }
        return 0;
    }
};