// First time
/*
    Use two flag to record we already found five or zero
    T: O(n)/ S: O(1)
*/
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        bool five = false, zero = false;
        for (int i = n - 1; i >= 0; --i) {
            if ((zero && (num[i] == '0' || num[i] == '5')) || (five && (num[i] == '2' || num[i] == '7')))
                return n - i - 2;
            if (num[i] == '0') zero |= 1;
            if (num[i] == '5') five |= 1;
        }
        if (zero)
            return n - 1;
        else
            return n;
    }
};

/*
    check the end of num is "25", "75", "50", "00" or not, then compare which operation is less
    Notice if the end is "0", it can be remained
    T: O(n)/ S: O(1)
*/
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length(), ret5 = 0, ret0 = 0;
        for (int i = n - 1; i >= 0; --i) {
            ret5++;
            if (num[i] == '5') {
                while (--i >= 0) {
                    // Here ret5-- is for '5', we can remain it because we already find "25" or "75"
                    if (num[i] == '2' || num[i] == '7') {ret5--; break;}
                    else ret5++;
                }
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            ret0++;
            if (num[i] == '0') {
                // Here should ret0-- first because '0' can be remained anyway
                ret0--;
                while (--i >= 0) {
                    if (num[i] == '5' || num[i] == '0') break;
                    else ret0++;
                }
                break;
            }
        }
        return min(ret0, ret5);
    }
};