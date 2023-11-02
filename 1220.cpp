// First time
/*
    a -> e
    e -> a, i
    i -> a, e, o, u
    o -> i, u
    u -> a
    Just check what letter is the end of i-1 length string
    e.g. 'a' need to follow after 'e', 'i', 'u'
         -> add previous count of 'e', 'i', 'u'

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countVowelPermutation(int n) {
        int ret = 0, mod = 1e9 + 7;
        // {a, e, i, o, u}
        vector<long long> cur(5, 1);
        for (int i = 2; i <= n; ++i) {
            vector<long long> pre = cur;
            cur[0] = (pre[1] + pre[2] + pre[4]) % mod;
            cur[1] = (pre[0] + pre[2]) % mod;
            cur[2] = (pre[1] + pre[3]) % mod;
            cur[3] = pre[2];
            cur[4] = (pre[2] + pre[3]) % mod;
        }
        return (accumulate(cur.begin(), cur.end(), 0L)) % mod;
    }
};