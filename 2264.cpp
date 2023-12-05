// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    string largestGoodInteger(string num) {
        char ret = 0;
        for (int i = 1; i < num.length() - 1; ++i) {
            if (num[i] == num[i - 1] && num[i] == num[i + 1] && num[i] > ret) {
                ret = num[i];
            }
        }
        return ret == 0 ? "" : string(3, ret);
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string largestGoodInteger(string num) {
        string ret = "";
        for (int i = 1; i < num.length() - 1; ++i) {
            if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                string tmp = num.substr(i - 1, 3);
                if (tmp > ret)
                    ret = tmp;
            }
        }
        return ret;
    }
};