// First time
/*
    The same concept with iteration
    Use n^(n-1) to represent 2^(k+1)-1
    e.g. 110^(110-1) = 110^101 = 011 -> for k=1
    then use n&=n-1 to remove the LSB

    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ret = 0;
        while (n > 0) {
            ret = -(ret + (n ^ (n - 1)));
            n &= n - 1;
        }
        return abs(ret);
    }
};

/*
    (2^0) 1   -> 0  : (2^1-1) 1 times
    (2^1) 10  -> 00 : (2^2-1) 3 times (10 -> 11 -> 01 -> 00)
    (2^2) 100 -> 000: (2^3-1) 7 times (100 -> 110 -> 010 -> 000)
                                            ^      ^      ^
                                        3 times  1 time  3 times
    So change 2^k to 0, need 2^(k+1)-1 times

    And if we need to change 111 to 0,
    because we have 11x already, so it can save 3 times (100 -> 110)
    If we consider last two bits x11, it's the same concept
    because we have x11 already, so it can save 1 time (10 -> 11)
    -> so 111 change to 000, need 7-(3-1) times

    T: O(logn)/S: O(logn)
*/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1)
            return n;
        int bit = 1;
        // find the nearest power of 2 larger than n
        while (bit <= n)
            bit <<= 1;
        return (bit - 1) - minimumOneBitOperations(n - (bit >> 1));
    }
};