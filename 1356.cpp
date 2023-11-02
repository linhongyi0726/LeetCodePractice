// First time
/*
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    static bool comp(int a, int b) {
        int bita = __builtin_popcount(a), bitb =  __builtin_popcount(b);
        if (bita != bitb)
            return bita < bitb;
        else
            return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};

class Solution {
public:
    static int countbit(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
    static bool comp(int a, int b) {
        int bita = countbit(a), bitb = countbit(b);
        if (bita != bitb)
            return bita < bitb;
        else
            return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};