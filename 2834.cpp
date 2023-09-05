// First time
/*
    The same with problem 2834
    -----
    Use hash set to record the sub-array, then be sure there isn't a pair for sum of k
    T: O(n)/S: O(n)
    -----
    math approach
    ex. n = 3, k = 5
    1, 2, 3 ,4
   |_| x |____|
   
    T: O(1)/S: O(1)
*/
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> st;
        long long sum = 0;
        for (int i = 1; st.size() < n; ++i) {
            if (st.count(target - i)) continue;
            st.insert(i);
            sum += i;
        }
        return sum;
    }
};

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long mid = target >> 1;
        if (n <= mid) return (n * (n + 1)) >> 1;
        return ((mid * (mid + 1)) >> 1) + (((n - mid) * (target + target + n - mid - 1)) >> 1);
    }
};