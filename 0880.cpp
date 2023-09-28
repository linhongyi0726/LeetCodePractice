// First time
/*
    Forward to get the index which can let the string length > k
    Backward to get the actually character at position k
        If it is digit, recover the length by /, and then compute the diff between k
        ex. s[i]=3, n=9, k=8
        |---|---|---| => |---| n=9/3=3, k=8%3=2
                  ^        ^
                  k        k
        Else if it is alpha, return it if k=n or k=0 (because we'll break the loop at next cycle, return it earlier)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = 0, i = 0;
        for (; n < k; ++i) {
            n = isalpha(s[i]) ? n + 1 : n * (s[i] - '0');
        }
        i--;
        while (i >= 0) {
            if (isalpha(s[i])) {
                // if (k % n == 0)
                if (k == n || k == 0)
                    return string(1, s[i]);
                else
                    n--;
            } else {
                n /= s[i] - '0';
                k %= n;
            }
            i--;
        }
        return "";
    }
};

// neat code
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = 0, i = 0;
        for (; n < k; ++i) {
            n = isalpha(s[i]) ? n + 1 : n * (s[i] - '0');
        }
        while (i--) {
            if (isdigit(s[i])) {
                n /= s[i] - '0';
                k %= n;
            } else {
                if (k % n)
                    n--;
                else
                    return string(1, s[i]);
            }
        }
        return "";
    }
};

// Calculate whole decode string length, then backward to get the position k
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = 0;
        for (int i = 0; i < s.length(); ++i) {
            n = isalpha(s[i]) ? n + 1 : n * (s[i] - '0');
        }
        for (int i = s.length() - 1; i >= 0; --i) {
            if (isdigit(s[i])) {
                n /= s[i] - '0';
                k %= n;
            } else {
                if (k == n || k == 0)
                    return string(1, s[i]);
                else
                    n--;
            }
        }
        return "";
    }
};

/*
    Brute-force -> MLE
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string decode = "";
        for (char &c : s) {
            if (c <= '9') {
                string tmp = decode;
                for (int i = 0; i < c - '1'; ++i) {
                    decode += tmp;
                    if (decode.length() >= k)
                        break;
                }
            } else {
                decode += c;
            }
            if (decode.length() >= k)
                break;
        }
        decode = decode[k - 1];
        return decode;
    }
};