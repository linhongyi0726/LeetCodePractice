// Second time
/*
    Follow-up: S: O(n) solution
    2 ptr at each string

    Iterate the string from the end, when we meet '#', skip one more character
    It support to be the same after we handle all of '#' from the end

    *Notice the outside while loop condition should be (si>=0 || ti>=0)
    to handle different length of string s and t
    T: O(n)/S: O(1)
    -----
    2 ptr at the same string
    right point iterate the string and
    use swap to change the confirmed character to left point
    Then iterate and compare the two string from each left point to the begin
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si = s.length() - 1, ti = t.length() - 1, back = 0;
        while (si >= 0 || ti >= 0) {
            back = 0;
            while (si >= 0 && (s[si] == '#' || back)) {
                if (s[si] == '#')
                    back++;
                else
                    back--;
                si--;
            }
            back = 0;
            while (ti >= 0 && (t[ti] == '#' || back)) {
                if (t[ti] == '#')
                    back++;
                else
                    back--;
                ti--;
            }
            if (si >= 0 && ti >= 0 && s[si] == t[ti]) {
                si--;
                ti--;
            } else {
                break;
            }
        }
        return si == -1 && ti == -1;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        for (char c : s) {
            if (c == '#' && !ss.empty())
                ss.pop();
            else if (c != '#')
                ss.push(c);
        }
        for (char c : t) {
            if (c == '#' && !st.empty())
                st.pop();
            else if (c != '#')
                st.push(c);
        }
        return ss == st;
    }
};


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