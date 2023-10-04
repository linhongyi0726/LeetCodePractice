// First time
/*
    Count "AAA" and "BBB"
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int tripleA = 0, tripleB = 0;
        for (int i = 1; i < colors.length() - 1; ++i) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A')
                    tripleA++;
                else
                    tripleB++;
            }
        }
        return tripleA > tripleB;
    }
};

class Solution {
public:
    bool winnerOfGame(string colors) {
        int tripleA = 0, tripleB = 0;
        for (int i = 1; i < colors.length() - 1; ++i) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                tripleA++;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                tripleB++;
        }
        return tripleA > tripleB;
    }
};