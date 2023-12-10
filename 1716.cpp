// First time
/*
    T: O(1)/S: O(1)
*/
class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, day = n % 7;
        return ((1 + 7) * 7 / 2) * week + 7 * ((week - 1) * week / 2) + (1 + day) * day / 2 + day * week;
    }
};