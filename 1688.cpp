// First time
/*
    To decide the only winner,
    we need to do n-1 tournaments to eliminate n-1 teams

    T: O(1)/S: O(1)
*/
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

/*
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int numberOfMatches(int n) {
        int ret = 0;
        while (n != 1) {
            ret += n / 2;
            n = (n + 1) / 2;
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfMatches(int n) {
        int ret = 0;
        while (n != 1) {
            if (n & 1) {
                ret += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            } else {
                ret += (n >> 1);
                n >>= 1;
            }
        }
        return ret;
    }
};