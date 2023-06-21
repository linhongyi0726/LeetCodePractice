// First time
/*
    Calculate the slope
    (Y1-Y0)/(X1-X0) = (Y2-Y0)/(X2-X0)
    change to multiplication to avoid denominator be 0
    -> (X2-X0)(Y1-Y0) = (X1-X0)(Y2-Y0)
    Constraints: 2 <= coordinates.length, so we can start for loop form index 2

    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0=coordinates[0][0], y0=coordinates[0][1];
        int x1=coordinates[1][0], y1=coordinates[1][1];
        for (int i=2; i<coordinates.size(); ++i) {
            int xn=coordinates[i][0], yn=coordinates[i][1];
            if ((x1-x0)*(yn-y0)!=(xn-x0)*(y1-y0)) return false;
        }
        return true;
    }
};