// Fist time
/*
    Use map to record the frequency of each character
    If size-maxf > k means we heave no more chance to change character,
    so we should shrink the window by 1
    T:O(n)/ S:O(1) -> the map only has 26 elements at most
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector<int> v(26, 0);
        unordered_map<char, int> freq;
        int ans=0, maxf=0, l=0, r=0;
        for (; r<s.length(); ++r) {
            maxf=max(maxf, ++freq[s[r]]);
            if (r-l+1-maxf > k) --freq[s[l++]];
            // Here don't need to check maximum, because the windows size won't decrease
            // ans=max(ans, r-l+1);
            ans=r-l+1;
        }
        return ans;
    }
};

// Use "size" instead of r/l to calculate windows size
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int ans=0, size=0, maxf=0;
        for (int i=0; i<s.length(); ++i) {
            maxf=max(maxf, ++freq[s[i]]);
            size++;
            if (size-maxf > k) --freq[s[i-(--size)]];
        }
        return size;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int size=0, maxf=0;
        for (int i=0; i<s.length(); ++i) {
            maxf=max(maxf, ++freq[s[i]]);
            if (size-maxf >= k) --freq[s[i-size]];
            else ++size;
        }
        return size;
    }
};