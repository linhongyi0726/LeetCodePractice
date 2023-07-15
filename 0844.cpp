// First time
/*
    Follow up: O(1) space complexity
    Use 2 ptr
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sl=0, tl=0;
        for (int sr=0; sr<s.length(); ++sr) {
            if (s[sr]=='#' && sl) --sl;
            else if (s[sr]!='#') swap(s[sl++], s[sr]);
        }
        for (int tr=0; tr<t.length(); ++tr) {
            if (t[tr]=='#' && tl) --tl;
            else if (t[tr]!='#') swap(t[tl++], t[tr]);
        }
        while (sl && tl) {
            if (s[--sl] != t[--tl]) return false;
        }
        return sl==tl;
    }
};

/*
    Use stack to record the final string
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '#') {
                if (!ss.empty()) ss.pop();
                else continue;
            }
            else ss.push(s[i]);
        }
        for (int i=0; i<t.length(); ++i) {
            if (t[i] == '#') {
                if (!st.empty()) st.pop();
                else continue;  
            }
            else st.push(t[i]);
        }
        /*
        while (!ss.empty() && !st.empty()) {
            if (ss.top() == st.top()) {ss.pop(); st.pop();}
            else break;
        }
        return ss.empty()&&st.empty();
        */
       return ss==st;
    }
};