// First time
/*
    Use Sieve of Eratosthenes to find prime
    If one number is prime, then set all its multiple non-prime
    T: O(nlog(logn))/S: O(n)
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n<2) return 0;
        int ans=0;
        vector<bool> prime(n, true);
        prime[0]=false;
        prime[1]=false;
        // Here only need to check until √n, then we can set all prime
        // but we want the count of all primes, so need another for loop to count
        for (int i=2; i<=sqrt(n); ++i) {
            if (prime[i]) {
                for (int j=2; i*j<n; ++j) {
                    prime[i*j]=false;
                }
            }
        }
        for (bool b:prime) {
            if (b) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> prime(n, true);
        for (int i=2; i<n; ++i) {
            if (prime[i]) {
                ans++;
                // for (long j=i; i*j<n; ++j)
                for (int j=2; i*j<n; ++j) {
                    prime[i*j]=false;
                }
            }
        }
        return ans;
    }
};