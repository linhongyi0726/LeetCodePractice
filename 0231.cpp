// First time
/*
    1000 & 0111 = 0
     (8)   (7)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && !(n&(n-1));
    }
};