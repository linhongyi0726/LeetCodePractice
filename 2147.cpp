// First time
/*
    DP
    dp[i][j] denote the ways to add divider at i-th element and the newest interval has j seats
    T: O(n)/S: O(n)
    -----
    Also can compress the array to reduce the space complexity
    use three variables to represent the number of seats in the interval
    T: O(n)/S: O(1)
*/
class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return dfs(corridor, 0, 0, dp);
    }
    int dfs(string &corridor, int i, int seat, vector<vector<int>> &dp) {
        if (i == corridor.length())
            return seat == 2;
        if (dp[i][seat] != -1)
            return dp[i][seat];
        int ways = 0;
        if (seat == 2) {
            if (corridor[i] == 'S') {
                // must need add divider
                ways = dfs(corridor, i + 1, 1, dp);
            } else {
                // no add divider + add divider
                ways = (dfs(corridor, i + 1, seat, dp) + dfs(corridor, i + 1, 0, dp)) % mod;
            }
        } else {
            // no need to add divider, keep move
            if (corridor[i] == 'S') {
                ways = dfs(corridor, i + 1, seat + 1, dp);
            } else {
                ways = dfs(corridor, i + 1, seat, dp);
            }
        }
        dp[i][seat] = ways;
        return dp[i][seat];
    }
};

class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7, seat0 = 1, seat1 = 0, seat2 = 0;
        for (char c : corridor) {
            if (c == 'S') {
                // add divider before this 'S'
                seat0 = (seat0 + seat2) % mod;
                // update the number of seats at this new interval
                seat2 = seat1;
                seat1 = seat0;
                seat0 = 0;
            } else {
                // compute the number of ways if we add the divider after this 'P'
                seat0 = (seat0 + seat2) % mod;
            }
        }
        return seat2;
    }
};

/*
    one pass without extra space

    |SxxSxxSxS|
    -> |SxxS|xxSxS|
       |SxxSx|xSxS|
       |SxxSxx|SxS|
             ^
    only compute the interval of two seats when the count is odd

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int numberOfWays(string corridor) {
        int ret = 1, pre = -1, cnt = 0, mod = 1e9 + 7;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                cnt++;
                if (cnt > 2 && cnt & 1)
                    ret = ((long long)ret * (i - pre)) % mod;
                pre = i;
            }
        }
        if (cnt & 1 || cnt == 0)
            return 0;
        return ret;
    }
};

/*
    Store all index of 'S', then calculate the possible ways by ret*(pos[i]-pos[i-1])
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int numberOfWays(string corridor) {
        int ret = 1, mod = 1e9 + 7;
        vector<int> pos;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S')
                pos.push_back(i);
        }
        int n = pos.size();
        if (n & 1 || n == 0)
            return 0;
        for (int i = 1; i < n / 2; i++) {
            ret = ((long long)ret * (pos[i * 2] - pos[i * 2 - 1])) % mod;
        }
        return ret;
    }
};