// First time
/*
    Sieve of Eratosthenes + two sum
    T: O(nlog(logn))/ S: O(n)
*/
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n, true);
        for (int i=2; i<=sqrt(n); ++i) {
            if (prime[i]) {
                /*
                for (int j=i*i; j<n; j+=i) {
                    prime[j]=false;
                }
                */
                for (int j=i; i*j<n; ++j) {
                    prime[i*j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i=2; i*2<=n; ++i) {
            // n-i<=1 will not be happened
            if (prime[i] && prime[n-i]) {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n, true);
        for (int i=2; i<=sqrt(n); ++i) {
            if (prime[i]) {
                for (int j=i; i*j<n; ++j) {
                    prime[i*j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i=2; i*2<=n; ++i) {
            if (prime[i]) {
                // Prime is not including 1
                if (n-i>1 && prime[n-i]) ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};