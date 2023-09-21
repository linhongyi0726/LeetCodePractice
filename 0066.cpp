// First time
/*
    Optimize
    1. Return earlier because we only add one so at most 9 -> 10
    2. Insert in the end to avoid extra time complexity
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

/*
    insert in the begin
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        int n = digits.size();
        digits[n - 1]++;
        for (int i = n - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        /*
            digits[0] = 1;
            digits.push_back(0);
        */
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            int tmp = 0;
            if (i == n - 1) {
                tmp = digits[i] + 1;
            } else {
                tmp = carry + digits[i];
            }
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};