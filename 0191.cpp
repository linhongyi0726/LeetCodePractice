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