// First time
/*
    Math approach

    Because the left half side in every row is the same with the previous row,
    and the right half side is opposite of left side number in relative position

    So when k > previous row's size, it must be flipped from the relative position in the previous row
    To compute the times we flip from 0, we should subtract the previous row's size until k=1,
    means we need to subtract k-1
    -> Because every row's size is power of 2, we can count how many bit 1 in k-1,
       then we can know how many times we need to subtract (aka flip from 0)
    If we flip odd times -> the answer is 1
    If we flip even times -> the answer is 0

    e.g.
        n=1 0
            ^
        n=2 01
            ^
        n=3 0110
            ^ (flip) -> k=1
        n=4 01011001
                ^ (flip) -> it's flipped from the number in k=5-4
        n=5 0110100110010110
                        ^
                        k=13 -> it's flipped from the number in k=13-8
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};

class Solution {
public:
    int kthGrammar(int n, int k) {
        int times = 0;
        k -= 1;
        for (; k > 0; k &= (k - 1))
            ++times;
        return times & 1;
    }
};

/*
    Treat it a binary tree
    If k is even, its parent is k/2
    If k is odd, its parent is (k+1)/2
    e.g.
        n=1            0
                  /         \
        n=2      0           1
               /   \       /   \
        n=3   0     1     1     0
             / \   / \   / \   / \
        n=4 0   1 1   0 1   0 0   1
         k: 1   2 3   4 5   6 7   8

    *Notice when k is even, it's different with its parent (so we can do 1^ to flip it)
    parent  child
      0   ->  01
               ^
      1   ->  10
               ^

    recursion: T: O(n)/S: O(n)
    iteration: T: O(n)/S: O(1)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        if (k % 2 == 0)
            return 1 ^ kthGrammar(n - 1, k / 2);
        else
            return kthGrammar(n - 1, (k + 1) / 2);
    }
};

// the same idea but we only need to compute until k=1
// recursion
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1)
            return 0;
        if (k % 2 == 0)
            return 1 ^ kthGrammar(n, k / 2);
        else
            return kthGrammar(n, (k + 1) / 2);
    }
};

// iteration
class Solution {
public:
    int kthGrammar(int n, int k) {
        int ret = 0;
        while (k > 1) {
            if (k % 2 == 0) {
                k /= 2;
                ret ^= 1;
            } else {
                k = (k + 1) / 2;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int kthGrammar(int n, int k) {
        int ret = 0;
        while (k > 1) {
            if (k % 2 == 0)
                k /= 2;
            else
                k += 1;
            ret ^= 1;
        }
        return ret;
    }
};

/*
    The left half side of number is from the previous row
    and the right half side of number is opposite of left side number in relative position
    (1 -> 0, 0 -> 1)
    p.s. the size of every row is 2^(n-1)

    e.g.
        n=1 0
        n=2 01
        n=3 0110
        n=4 01101001 ->  0110 1001
                        |____|____|
                          ^     ^
            the same with n=3   opposite of left side

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        int prev = pow(2, n - 2);
        if (k <= prev)
            return kthGrammar(n - 1, k);
        else
            return 1 ^ kthGrammar(n - 1, k - prev);
            // return 1 - kthGrammar(n - 1, k - prev);
    }
};