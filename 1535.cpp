// First time
/*
    If don't find the winner after one pass,
    the winner must be the maximum of arr

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), win = arr[0], cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (win > arr[i]) {
                cnt++;
            } else {
                cnt = 1;
                win = arr[i];
            }
            if (cnt == k)
                break;
        }
        return win;
    }
};

/*
    Use deque to simulate the game operation
    Notice when k > arr.size(), it will compare repeated
    So we can reduce the time complexity by changing k to arr.size() if it's greater then arr.size()

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> dq(arr.begin(), arr.end());
        int n = arr.size(), cnt = 0, win = 0, lose = 0;
        k = k > n ? n : k;
        while (1) {
            int first = dq.front();
            dq.pop_front();
            int second = dq.front();
            dq.pop_front();
            if (first > second) {
                if (win == first)
                    cnt++;
                else
                    cnt = 1;
                win = first;
                lose = second;
            } else {
                if (win == second)
                    cnt++;
                else
                    cnt = 1;
                win = second;
                lose = first;
            }
            if (cnt == k)
                break;
            dq.push_back(lose);
            dq.push_front(win);
        }
        return win;
    }
};