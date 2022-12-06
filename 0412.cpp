// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0)
                ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            string s = "";
            if (i % 3 == 0) s += "Fizz";
            if (i % 5 == 0) s += "Buzz";
            if (s.empty()) s += to_string(i);
            ans.push_back(s);
        }
        return ans;
    }
};