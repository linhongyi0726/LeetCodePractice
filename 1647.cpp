// First time
/*
    Greedy without hash set
    Sort the frequency then compare the neighboring frequency from largest to smallest
    Let every freq[i] differ from freq[i+1] at least 1
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        int ret = 0;
        for (char &c : s)
            freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        for (int i = 24; i >= 0; --i) {
            if (freq[i] == 0)
                break;
            if (freq[i] >= freq[i + 1]) {
                int prev = freq[i];
                freq[i] = max(0, freq[i + 1] - 1);
                ret += prev - freq[i];
            }
        }
        return ret;
    }
};

/*
    Use hash map or vector to record the frequency of each character
    And use another hash set to record the used frequency
    T:O(n)/S: O(n)
*/
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        unordered_set<int> st;
        int ret = 0;
        for (char &c : s)
            mp[c]++;
        for (auto &[c, cnt] : mp) {
            while (st.count(cnt)) {
                ret++;
                cnt--;
            }
            if (cnt > 0)
                st.insert(cnt);
        }
        return ret;
    }
};