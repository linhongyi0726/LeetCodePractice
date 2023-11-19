// First time
/*
    set the bit from n-1 to 0, there are cases
    1. a and b are both set this bit -> skip
    2. a and b are both no set this bit -> set bit in a and b
    3. a and b only one is set this bit
       -> move this bit to smaller number, it will let the product bigger
       e.g.
       57 * 17 = 969
       (57-8) * (17+8) = 1225

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long mod = 1e9 + 7;
        for (int i = n - 1; i >= 0; --i) {
            long long bit = 1LL << i;
            if ((min(a, b) & bit) == 0) {
                a ^= bit;
                b ^= bit;
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long mod = 1e9 + 7;
        for (int i = n - 1; i >= 0; --i) {
            long long bit = 1LL << i;
            if ((a & bit) && (b & bit))
                continue;
            if ((a & bit) == 0 && (b & bit) == 0) {
                a |= bit;
                b |= bit;
            } else if (a > b) {
                a &= ~bit;
                b |= bit;
            } else {
                a |= bit;
                b &= ~bit;
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};