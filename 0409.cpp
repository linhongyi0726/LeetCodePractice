// First time
/*
    Count every character numbers by a hash map (or can use char[52])
    If odd number exist in the hash map, need to plus 1
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        bool isodd = false;
        for (char c : s)
            mp[c]++;
        for (auto n : mp) {
            ans += n.second/2;
            if (n.second%2 != 0)
                isodd = true;
        }
        return ans*2+isodd;
    }
};

/*
    Count how many odd number in the hash map
    Then if there is any odd number exit, plus 1
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        bool isodd = false;
        for (char c : s) mp[c]++;
        for (auto n : mp) {
            if (n.second & 1) {
                isodd = true;
                count++;
            }
        }
        return s.size() - count + isodd;
    }
};