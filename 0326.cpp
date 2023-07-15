// First time
/*
    n = 3^x
    log(n) = x*log(3)
    x = log(n)/log(3) -> must be positive integer

    Those approach can't work because of floating-point precision??
    pow(3, log10(n)/log10(3)) == n
    fmod(log10(n), log10(3)) == 0
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && fmod(log10(n)/log10(3), 1) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && floor(log10(n)/log10(3)) == log10(n)/log10(3);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && log10(n)-(int)(log10(n)/log10(3))*log10(3) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n != 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};