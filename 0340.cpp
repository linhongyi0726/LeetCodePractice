// First time
/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int ret=0, l=0, r=0;
        for (; r<s.length(); ++r) {
            ++cnt[s[r]];
            // no need to shrink l too many times, because we want the longest window
            // while (cnt.size() > k)
            if (cnt.size() > k) {
                if (--cnt[s[l]]==0) cnt.erase(s[l]);
                ++l;
            }
            ret=max(ret, r-l+1);
        }
        return ret;
    }
};