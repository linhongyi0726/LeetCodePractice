// First time
/*
    Cantor's Diagonalization (https://en.wikipedia.org/wiki/Cantor%27s_diagonal_argument)
    Since we are given that number of bits in the number is equal to number of elements
    Choose one bit in every elements then flip it,
    thus we can ensure this number is unequal with original element

      [1]  1   1 ,
       0  [1]  1 ,
       0   0  [1],
      -----------
       1   1   1
    -> 0   0   0 -> must not in the array

    the same as:
       1   1  [1],
       0  [1]  1 ,
      [0]  0   1 ,
      -----------
       0   1   1
    -> 1   0   0 -> must not in the array

    T: O(n)/S: O(1)
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ret = "";
        for (int i = 0; i < nums.size(); ++i) {
            ret += nums[i][i] == '0' ? '1' : '0';
        }
        return ret;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ret = "";
        for (int i = 0; i < nums.size(); ++i) {
            ret += nums[nums.size() - 1 - i][i] == '0' ? '1' : '0';
        }
        return ret;
    }
};

/*
    Use stoi to convert string to binary,
    and use bitset to convert it back to string

    T: O(n)/S: O(n)
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (string num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        for (int i = 0; i <= n; ++i) {
            if (!st.count(i))
                return bitset<16>(i).to_string().substr(16 - n);
        }
        return "";
    }
};

/*
    Backtracking
    because the nums.size() is the same with the number of bits
    we only need to check 00...0 -> 10...0 -> 11...0 -> ... -> 11...1
    (a special case in backtracking)
    T: O(n)/S: O(n)
    -----
    Use ans variable to check we found answer or not
    T: O(2^n)/S: O(n)
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string s(nums.size(), '0');
        return dfs(st, s, 0);
    }
    string dfs(unordered_set<string> &st, string &s, int i) {
        if (!st.count(s))
            return s;
        s[i] = '1';
        return dfs(st, s, i + 1);
        // s[i] = '0';
        // return dfs(st, s, i + 1);
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        return dfs(st, "", nums.size());
    }
    string dfs(unordered_set<string> &st, string s, int n) {
        if (s.length() == n) {
            if (!st.count(s))
                return s;
            else
                return "";
        }
        string ans = "";
        ans = dfs(st, s + "1", n);
        if (ans != "")
            return ans;
        ans = dfs(st, s + "0", n);
        if (ans != "")
            return ans;
        return "";
    }
};

/*
    convert to binary and sort to find missing number,
    then convert it back before return

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            v[i] = s2i(nums[i], n);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (v[i] != i)
                return i2s(i, n);
        }
        return i2s(v.size(), n);
    }
    int s2i(string s, int n) {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                num += (1 << (n - 1 - i));
        }
        return num;
    }
    string i2s(int num, int n) {
        string s = "";
        while (n) {
            if (num & (1 << (n - 1)))
                s += "1";
            else
                s += "0";
            n--;
        }
        return s;
    }
};