// First time
/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t="";
        for (string word:words) t+=word[0];
        return t==s;
    }
};

/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size()!=s.length()) return false;
        for (int i=0; i<s.length(); ++i) {
            if (words[i][0]!=s[i]) return false;
        }
        return true;
    }
};