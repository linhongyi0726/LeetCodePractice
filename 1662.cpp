// First time
/*
    one pass to iterate all word1 and word2
    if they are equal, suppose idx1 and idx2 will move to the end of array when it end the loop

    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // word array index: idx1, idx2
        // char index: i, j
        int idx1 = 0, idx2 = 0, i = 0, j = 0, n = word1.size(), m = word2.size();
        while (idx1 < n && idx2 < m) {
            if (word1[idx1][i] != word2[idx2][j])
                return false;
            if (++i == word1[idx1].length()) {
                idx1++;
                i = 0;
            }
            if (++j == word2[idx2].length()) {
                idx2++;
                j = 0;
            }
        }
        return idx1 == n && idx2 == m;
    }
};

/*
    Use string concatenation
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (string s : word1)
            s1 += s;
        for (string s : word2)
            s2 += s;
        return s1 == s2;
    }
};