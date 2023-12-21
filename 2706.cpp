// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1 = INT_MAX, mn2 = INT_MAX, leftover = 0;
        for (int price : prices) {
            if (price < mn1) {
                mn2 = mn1;
                mn1 = price;
            } else if (price < mn2) {
                mn2 = price;
            }
        }
        leftover = money - mn1 - mn2;
        return leftover < 0 ? money : leftover;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int leftover = money - prices[0] - prices[1];
        return leftover < 0 ? money : leftover;
    }
};