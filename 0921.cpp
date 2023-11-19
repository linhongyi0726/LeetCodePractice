// First time
/*
    without stack, because there is only '(' and ')'
    l represent we need to add left parentheses '('
    r represent we need to add right parentheses ')'

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') {
                r++;
            } else if (r > 0) {
                r--;
            } else {
                l++;
            }
        }
        return l + r;
    }
};

// easier to understand the logic
class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') {
                r++;
            } else {
                if (r > 0)
                    r--;
                else
                    l++;
            }
        }
        return l + r;
    }
};

/*
    with stack
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(c);
        }
        return st.size();
    }
};