// First time
/*
    The same with problem 2865
    Find the left and right prefix sum, then calculate the maximum
    When we calculate prefix sum, need to use monotonic stack to record the index of increasing element

    ex. calculate left prefix sum
    [5, 3, 4, 1, 1]
     ^
    |__| stack: [0] -> push '0'

    [5, 3, 4, 1, 1]
        ^
       |__| stack: [1] -> pop '0' and push '1' because 3 < 5
    
    [5, 3, 4, 1, 1]
           ^
       |_____| stack: [1, 2] -> push '2' directly
    
    [5, 3, 4, 1, 1]
              ^
             |__| stack: [3] -> pop '1' and '2' then push '3' because 1 < 3 and 1 < 4
    
    [5, 3, 4, 1, 1]
                 ^
             |____| stack: [3, 4] -> push '4' directly

    maxHeights:        [5, 3, 4,  1, 1]
    left prefix sum -> [5, 6, 10, 4, 5]
                       [13, 8, 6, 2, 1] <- right prefix sum
                 ret: [13, 11, 12, 5, 5]
        left[i] + right[i] - maxHeights[i] because the peak will be counted twice

    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> left(n, 0), right(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            if (st.empty())
                left[i] = (long long)(i + 1) * maxHeights[i];
            else
                left[i] = left[st.top()] + (long long)(i - st.top()) * maxHeights[i];
            st.push(i);
        }
        // Some approaches to clear a stack
        // while (!st.empty()) st.pop();
        // st = stack<int>();
        stack<int>().swap(st);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            if (st.empty())
                right[i] = (long long)(n - i) * maxHeights[i];
            else
                right[i] = right[st.top()] + (long long)(st.top() - i) * maxHeights[i];
            st.push(i);
        }
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, left[i] + right[i] - maxHeights[i]);
        }
        return ret;
    }
};

/*
    Brute-force (optimize the while loop termination)
    Find all possible peak then compute the sum
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long sum = accumulate(maxHeights.begin(), maxHeights.end(), 0LL);
        priority_queue<pair<int, int>> pq;
        for (int i = 0 ; i < maxHeights.size(); ++i)
            pq.push({maxHeights[i], i});
        long long ret = 0;
        int times = 0;
        while (!pq.empty() && times <= maxHeights.size() / 2 && times < 500) {
            long long cnt = 0;
            int idx = pq.top().second;
            vector<int> tmp = maxHeights;
            times++;
            for (int j = idx; j > 0; --j) {
                if (tmp[j - 1] > tmp[j]) {
                    cnt += tmp[j - 1] - tmp[j];
                    tmp[j - 1] = tmp[j];
                }
            }
            for (int j = idx; j < tmp.size() - 1; ++j) {
                if (tmp[j] < tmp[j + 1]) {
                    cnt += tmp[j + 1] - tmp[j];
                    tmp[j + 1] = tmp[j];
                }
            }
            pq.pop();
            ret = max(ret, sum - cnt);
        }
        return ret;
    }
};

/*
    Brute-force the same with problem 2865
    Here will TLE because of the constraints of n up to 10^5
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ret = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            int peak = maxHeights[i];
            for (int j = i; j >= 0; --j) {
                peak = min(peak, maxHeights[j]);
                sum += peak;
            }
            peak = maxHeights[i];
            for (int j = i; j < n; ++j) {
                peak = min(peak, maxHeights[j]);
                sum += peak;
            }
            ret = max(ret, sum - maxHeights[i]);
        }
        return ret;
    }
};