// First time
/*
    handle multiple 1 and alone 1 cases
    If there is multiple 1 in the end, we can add 1 to let it be alone 1
    (e.g. 0011 -> 0100)
    If there is alone 1 in the end, we can directly subtract it
    (e.g. 0001 -> 0000)
    If there isn't any 1 in the end, we just left shift it until 1 be in the end

    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        while (n) {
            if ((n & 3) == 3) {
                // ...0011
                ret++;
                n++;
            } else if ((n & 1) == 1) {
                // ...0001
                ret++;
                n >>= 1;
            } else {
                // ...0010 or ...0000
                n >>= 1;
            }
        }
        return ret;
    }
};

/*
    Greedy
    First we can check how many times we need to add
    -> If add a power of 2 can decrease the number of bits, we add it
    Then the remain bit we can use subtraction to remove

    T: O(logn)/S: O(1)
    -----
    Another greedy
    Our goal is to make n=0, and what we can do is add/subtract power of 2
    So if we can let n become any power of 2, we can just subtract it
    -> choose the nearest power of 2 from n,
       then do another loop to compute its diff between n until n=0
    e.g.
    39 -> high: 64
          low:  32 diff 7 -> high: 8 diff 1 -> high: 2
                             low:  4           low:  1 diff 0
                    ^                  ^                ^
              subtract 32         subtract 8           add 1
              (= 7)               (= -1)               (= 0)

    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int minOperations(int n) {
        int ret = 0, m = log2(n);
        for (int i = 0; i <= m; ++i) {
            if (__builtin_popcount(n + (1 << i)) < __builtin_popcount(n)) {
                n += (1 << i);
                ret++;
            }
        }
        return ret + __builtin_popcount(n);
    }
};

class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        while (n) {
            ret++;
            int high = pow(2, (int)log2(n) + 1);
            int low = pow(2, (int)log2(n));
            if (high - n < n - low)
                n = high - n;
            else
                n = n - low;
        }
        return ret;
    }
};