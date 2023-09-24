// First time
/*
    The same with problem 2866
    See detail explanation in problem 2866
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
    Brute-force
    Find all possible peak then compute the sum
    T: O(n^2)/S: O(n)
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

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long sum = accumulate(maxHeights.begin(), maxHeights.end(), 0LL);
        priority_queue<pair<int, int>> pq;
        for (int i = 0 ; i < maxHeights.size(); ++i)
            pq.push({maxHeights[i], i});
        long long ret = 0;
        while (pq.size() > maxHeights.size() / 2) {
            long long cnt = 0;
            int idx = pq.top().second;
            vector<int> tmp = maxHeights;
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