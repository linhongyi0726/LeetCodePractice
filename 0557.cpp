// First time
/*
    Use stack to reverse string
    T: O(n^2)/S: O(n)
    -----
    Use reverse() or swap(), the time complexity of reverse() is O(n)
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for (int l = 0, r = 0; r <= n; ++r) {
            if (r == n || s[r] == ' ') {
                /*
                int tmpl = l, tmpr = r - 1;
                while (tmpl <= tmpr) {
                    swap(s[tmpl++], s[tmpr--]);
                }
                */
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
        }
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        stack<char> st;
        for (char c : s) {
            if (c != ' ') {
                st.push(c);
            } else {
                while (!st.empty()) {
                    ret += st.top();
                    st.pop();
                }
                ret += " ";
            }
        }
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};