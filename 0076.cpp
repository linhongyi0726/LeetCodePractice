// First time
/*
    sliding windows + one hash map (or 128 size vector which is faster)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        // vector<int> tbl(128, 0);
        unordered_map<char, int> mp;
        int l=0, r=0, count=0, start=0, strlen=INT_MAX;
        for (char c:t) mp[c]++;
        for (; r<s.length(); ++r) {
            if (mp[s[r]]-- > 0) count++;
            // when all char of string t in the windows,
            // the map value of them will be 0 and others will be negative
            while (count == t.length()) {
                if (r-l+1 < strlen) {
                    start = l;
                    strlen = r-l+1;
                }
                if (mp[s[l]] == 0) count--;
                mp[s[l]]++;
                l++;
            }
        }
        return strlen==INT_MAX?"":s.substr(start, strlen);
    }
};

/*
    sliding windows + two hash map to count char in two string
    *Note: just record the substr start and len, then substr() at the end to avoid MLE
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        // "count" denote how many char of string t in the windows
        int l=0, r=0, count=0, start=0, strlen=INT_MAX;
        for (char c:t) mpt[c]++;
        for (; r<s.length(); ++r) {
            // Move l and r to the start
            while (r<s.length() && !mpt.count(s[l])) {l++; r++;}
            // Update map for every char of string t in string s
            if (mpt.count(s[r]) && mps[s[r]]++ < mpt[s[r]]) count++;
            // Windows already include all char of string t
            while (count == t.length()) {
                // Update minium substr start and len
                if (r-l+1 < strlen) {
                    start = l;
                    strlen = r-l+1;
                }
                // We will move l 1 step at least,
                // if that will let our windows not include all char of string t, count--
                if (--mps[s[l]] < mpt[s[l]]) count--;
                // Move l to next char of string t
                while (++l<r && !mpt.count(s[l]));
            }
        }
        return strlen==INT_MAX?"":s.substr(start, strlen);
    }
};