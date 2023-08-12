// First time
/*
    Use vector count's index to represent height
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101, 0);
        int ans=0, p=0;
        for (int h:heights) count[h]++;
        for (int h:heights) {
            while (!count[p]) p++;  // Move form 0 so we will visited the smallest height
            if (p!=h) ans++;
            count[p]--;
        }
        return ans;
    }
};

/*
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int ans=0;
        for (int i=0; i<heights.size(); ++i) {
            if (heights[i]!=expected[i]) ans++;
        }
        return ans;
    }
};