// First time
/*
    Divide 10 to count the digits
    T: O(nm)/S: O(1)
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0, digits=0;
        for (int num:nums) {
            digits=0;
            while (num) {
                num/=10;
                digits++;
            }
            if (!(digits&1)) ans++;
        }
        return ans;
    }
};

/*
    Use log10(n)+1 to count the digits
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (int num:nums) {
            if (!(((int)log10(num)+1)&1)) ans++;
        }
        return ans;
    }
};

/*
    Constraints:
    1 <= nums[i] <= 10^5
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (int num:nums) {
            if ((num>=10&&num<=99) || (num>=1000&&num<=9999) || (num==100000)) ans++;
        }
        return ans;
    }
};