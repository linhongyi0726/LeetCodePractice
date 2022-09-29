// First time
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) swap(a,b);
        int i = a.length()-1;
        int j = b.length()-1;
        bool carry = false;
        while (j >= 0) {
            if (a[i]=='1' && b[j]=='1') {
                a[i] = '0' + carry;
                carry = true;
            }
            else if (a[i]=='0' && b[j]=='0') {
                a[i] = '0' + carry;
                carry = false;
            }
            else
                a[i] = '0' + !carry;
            --i;
            --j;
        }
        while (i >= 0 && carry) {
            if (a[i] == '0') {
                a[i] = '1';
                carry = false;
            }
            else
                a[i] = '0';
            --i;
        }
        return carry ? ('1'+a) : a;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) swap(a,b);
        string fill(a.length()-b.length(), '0');
        b = fill + b;
        int i = a.length()-1;
        bool carry = false;
        while (i >= 0) {
            if (a[i]=='1' && b[i]=='1') {
                a[i] = carry ? '1' : '0';
                carry = true;
            }
            else if (a[i]=='0' && b[i]=='0') {
                a[i] = carry ? '1' : '0';
                carry = false;
            }
            else
                a[i] = carry ? '0' : '1';
            --i;
        }
        return carry ? ('1'+a) : a;
    }
};