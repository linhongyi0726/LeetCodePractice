// First time
/*
    Notice the overflow when calculating power
    There are two methods to avoid it:
    1. when exponent is even, we can let base^2 and exponent/2 -> it will be the same
       when exponent is odd, we just multiply one times to let the exponent be even
       Notice do modulus every time when we do multiply, to avoid overflow
    2. Just use for loop to multiply the exponent times,
       and do modulus in every loop to avoid overflow

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long powerMod(long long base, long long exponent, long long modulus) {
        long long result = 1;
        base = base % modulus;
        while (exponent) {
            if (exponent % 2) {
                result = (result * base) % modulus;
            }
            exponent = exponent / 2;
            base = (base * base) % modulus;
        }
        return result;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        for (int i = 0; i < variables.size(); ++i) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3]; 
            if (powerMod(powerMod(a, b, 10), c, m) == target)
                ret.push_back(i);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        for (int i = 0; i < variables.size(); ++i) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            // ans1 = (a^b) % 10
            int ans1 = 1;
            while (b--) {
                ans1 = (ans1 * a) % 10;
            }
            // ans2 = (ans1)^c % m = ((a^b) % 10)^c % m
            int ans2 = 1;
            while (c--) {
                ans2 = (ans2 * ans1) % m;
            }
            if (ans2 == target)
                ret.push_back(i);
        }
        return ret;
    }
};