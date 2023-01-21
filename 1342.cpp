// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num) {
            if (num & 1) num--;
            else num >>= 1;
            ans++;
        }
        return ans;
    }
};