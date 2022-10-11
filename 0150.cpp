// First time
/*
    Reverse Polish notation (postfix expression)
    Use stack iterative (left->right)
    T: O(n)/S: O(n)
    *Notice the overflow of int
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        long l, r;
        for (string token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/")
                s.push(stoi(token));
            else {
                r = s.top(); s.pop();
                l = s.top(); s.pop();
                if (token == "+") s.push(l+r);
                else if (token == "-") s.push(l-r);
                else if (token == "*") s.push(l*r);
                else if (token == "/") s.push(l/r);
            }
        }
        return s.top();
    }
};

/*
    Recursive (right->left)
    ["4","13","5","/","+"]
    Change it to expression tree and traversal (NRL)
      +
     / \
    4   /
       / \
     13   5
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long l, r;
        string token = tokens.back(); tokens.pop_back();
        if (token != "+" && token != "-" && token != "*" && token != "/")
            return stoi(token);
        r = evalRPN(tokens);
        l = evalRPN(tokens);
        if (token == "+") return l+r;
        else if (token == "-") return l-r;
        else if (token == "*") return l*r;
        else return l/r;
    }
};