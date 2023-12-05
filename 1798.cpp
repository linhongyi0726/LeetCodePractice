// First time
/*
    Actually "ret" denote the minium number that we can't make
    So we can init ret to 1 when array coins is empty -> 1 is our next goal to make
    []    -> can make the number [0], next goal is 1
    [1]   -> can make the number [0:1], next goal is 2
    [1,2] -> can make the number [0:3], next goal is 4
             And the next value we want must <= 4, it can let the number we made be continuous
             e.g. if next number is 3, indicate we can make the number [0:6] ([0:3+3])
                    -> 6: 3+3, 5: 3+2, 4: 3+1
                  if next number is 5, we can't make number 4 (next goal)

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ret = 1;
        for (int coin : coins) {
            if (coin <= ret)
                ret += coin;
            else
                break;
        }
        return ret;
    }
};