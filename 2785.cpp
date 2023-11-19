// First time
/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string vowels;
        for (char c : s) {
            if (st.count(c))
                vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int i = 0;
        for (char &c : s) {
            if (st.count(c))
                c = vowels[i++];
        }
        return s;
    }
};

/*
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    string sortVowels(string s) {
        string ret;
        string vowels;
        for (char c : s) {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
                    ret.push_back(c);
            } else {
                ret.push_back('*');
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int i = 0;
        for (char &c : ret) {
            if (c == '*')
                c = vowels[i++];
        }
        return ret;
    }
};