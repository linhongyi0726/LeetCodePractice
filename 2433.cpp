// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        for (int i = n - 1; i > 0; --i) {
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};

/*
    x ^ a = b -> a ^ b = x
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ret(n, 0);
        ret[0] = pref[0];
        for (int i = 1; i < pref.size(); ++i) {
            ret[i] = pref[i] ^ pref[i - 1];
        }
        return ret;
    }
};