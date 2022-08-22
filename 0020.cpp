// First time
/*
    Use a map to store the mapping between left/right brackets
    And use stack to save and match the incoming parentheses
    * Notice the edge case:
    ex. the string is right brackets first like ")[{}]" that will let stack empty
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {{'(',')'}, {'[',']'}, {'{','}'}};
        stack<char> mystack;
        for (char c : s) {
            if (mp.count(c))
                mystack.push(c);
            else if (mystack.empty() || mp[mystack.top()] != c)
                return false;
            else
                mystack.pop();
        }
        return mystack.empty();
    }
};