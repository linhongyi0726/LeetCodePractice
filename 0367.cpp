// First time
/*
    1 = 1
    1+3 = 4
    1+3+5 = 9
    1+3+5+7 = 16
    T: O(√n)/ S: O(1) -> worse then binary search
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int odd=1;
        while (num > 0) {
            num -= odd;
            odd += 2;
        }
        return num==0;
    }
};

/*
    Binary search
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0, r=num;
        while (l <= r) {
            long m = l+(r-l)/2;
            if (m*m == num) return true;
            else if (m*m > num) r = m-1;
            else l = m+1;
        }
        return false;
    }
};

/*
    Newton's method
    It's the same as Problem 69
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long sq = num;
        while (sq*sq > num) {
            sq = (sq + num/sq)/2;
        }
        return sq*sq==num;
    }
};