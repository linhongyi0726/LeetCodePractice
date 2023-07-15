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