// First time
/*
    Convert integer to string then compare form both side
    T: O(nm)/S: O(1)
*/
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (; low <= high; ++low) {
            string s = to_string(low);
            int n = s.length(), l = 0, r = n - 1, left = 0, right = 0;
            if (n & 1) continue;
            while (l < r) {
                left += s[l++];
                right += s[r--];
                // left += s[l++] - '0';
                // right += s[r--] - '0';
            }
            if (left == right) ++ret;
        }
        return ret;
    }
};

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (; low <= high; ++low) {
            string s = to_string(low);
            int n = s.length(), left = 0, right = 0;
            if (n & 1) continue;
            for (int i = 0; i < n / 2; ++i) left += s[i];
            for (int i = n / 2; i < n; ++i) right += s[i];
            if (left == right) ++ret;
        }
        return ret;
    }
};

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (; low <= high; ++low) {
            string s = to_string(low);
            int n = s.length(), tmp = 0;
            if (n & 1) continue;
            for (int i = 0; i < n / 2; ++i) tmp += s[i] - s[n - 1 - i];
            if (tmp == 0) ++ret;
        }
        return ret;
    }
};

/*
    1. count how many numbers of digits then skip the odd number
    2. use "left" and "right" to accumulate the sum of digits
    ex. 2103
    left: 2103 / 10^3 = 2 -> 2103 - (2 * 10^3) = 103 (remove the left digit)
    right 2103 % 10 = 3 -> 2103 / 10 = 210 (remove the right digit)

    T: O(nm)/S: O(1)
*/
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (; low <= high; ++low) {
            int tmp = low, digits = 0;
            while (tmp) {
                digits++;
                tmp /= 10;
            }
            if (digits & 1) continue;
            int left = 0, right = 0;
            tmp = low;
            while (digits) {
                right += tmp % 10;
                int pow10 = pow(10, digits-1);
                left += tmp / pow10;
                tmp -= (tmp / pow10)*pow10;
                tmp /= 10;
                digits -= 2;
            }
            if (left == right) ret++;
        }
        return ret;
    }
};