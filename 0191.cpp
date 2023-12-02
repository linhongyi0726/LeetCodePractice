// Second time
/*
    If this function is called many times, we can optimize it to be more faster
    We group it and combine the bit in 2, 4, 8, 16, 32 bits

    e.g.
    in 8 bits, n = 0b00110110
    1. 2 bits group: use 0x55 (0b01010101)
        n & 0x55 = 0b00 01 01 00, (n>>1) & 0x55 = 0b 00 01 00 01
        -> 0b 00 10 01 01 (new n), it represents how many bits in 2 bits group of original n
           0b 00 11 01 10 (original n)
    2. 4 bits group: use 0x33 (0b00110011)
        n & 0x33 = 0b 00 10 00 01, (n>>2) & 0x33 = 0b 00 00 00 01
        -> 0b 00 10 00 10 (new n), it represents how many bits in 4 bits group of previous n
           0b 00 10 01 01 (previous n)
    3. 8 bits group: use 0x0f (0b00001111)
        n & 0x0f = 0b 00 00 00 10, (n>>4) & 0x0f = 0b 00 00 00 10
        -> 0b 00 00 01 00 (the answer), it represents how many bits in 8 bits group of previous n
           0b 00 10 00 10 (previous n)

    T: O(1)/S: O(1)
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }
};

/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            ret++;
            n &= (n - 1);
        }
        return ret;
    }
};


// First time
/*
    n           0110
    ~n          1001
    -n (~n+1)   1010
    n -= n&-n -> 0110 - 0010 = 0100 -> remove the last 1 bit

    T: (n)/S: O(1)
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans++;
            n -= n&-n;
        }
        return ans;
    }
};

/*
    T: (n)/S: O(1)
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans++;
            n &= (n-1);
        }
        return ans;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n&1;
            n >>= 1;
        }
        return ans;
    }
};