// First time
/*
    '_' need to be replaced the same direction,
    depends on which direction is more
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x = 0, l = 0, r = 0;
        for (char move : moves) {
            if (move == 'L') l++;
            else if (move == 'R') r++;
            else x++;
        }
        return x + abs(r - l);
    }
};