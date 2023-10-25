// Second time
/*
    Bit manipulation
    Need another condition to check is power of 2 or power of 4
    1. n&0x55555555
    2. (n-1)%3 = 0
        4^n-1 = (2^n+1) * (2^n-1) -> one of must be multiple of 3
        2^0 = 1  -> (1-1)%3 = 0
        2^1 = 2  -> (2+1)%3 = 0
        2^2 = 4  -> (4-1)%3 = 0
        2^3 = 8  -> (8+1)%3 = 0
        2^4 = 16 -> (16-1)%3 = 0
        2^5 = 32 -> (32+1)%3 = 0
        2^6 = 64 -> (64-1)%3 = 0
    T: O(1)/S: O(1)
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n & 0x55555555;
    }
};

/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0)
            return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

// First time
/*
    Use the judgement for "power of two" and filter
    0x5555 = 0101 0101 0101 0101
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && !(n&(n-1)) && n&0x55555555;
    }
};

/*
    4^n-1 = (2^n+1) * (2^n-1)
    one of 2^n+1 and 2^n-1 must be multiple of 3
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n-1)%3==0;
    }
};