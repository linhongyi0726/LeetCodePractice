// First time
/*
    x: the liters needed to transfer from addTank to mainTank
    x can be count by (mainTank-1)/4, because we need 1 add fuel and 4 mainTank fuel
                A             A
    [1 2 3 4 5] 6 [7 8 9 10] 11 [12 13 14 15]
    ans = (mainTank + x)*10 = [mainTank + min((mainTank-1)/4, addTank)]*10
    T: O(1)/S: O(1)
*/
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return (mainTank+min((mainTank-1)/4, additionalTank))*10;
    }
};

/*
    T: O(n)/S:(1)
*/
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int use=0;
        while (mainTank) {
            mainTank--;
            use++;
            if (use%5==0 && additionalTank) {
                mainTank++;
                additionalTank--;
            }
        }
        return use*10;
    }
};