// First time
/*
    After sort, strs[0] and strs[n-1] are the most different string, so just need to compare them
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        sort(strs.begin(), strs.end());
        for (int i=0; i<strs[0].length(); ++i) {
            if (strs[0][i]==strs[n-1][i]) ans+=strs[0][i];
            else break;
        }
        return ans;
    }
};