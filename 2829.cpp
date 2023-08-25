// First time
/*
    Use math and formula

    n=5, k=7
    1, 2, 3, 4, 5, 6,|7, 8
          ^  x  x     ^
         mid          k
   |_______|         |____|
    left sum        right sum
    Because [4,5] can pair with [3,2], we need to choose right element from k

    n=7, k=5
    1, 2, 3, 4,|5, 6, 7, 8, 9
       ^  x  x  ^
      mid       k
   |____|      |_____________|
  left sum        right sum

    T: O(1)/S: O(1)
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int mid=k/2;
        if (n<mid) return n*(1+n)/2;
        int remain=n-mid;
        // left sum: <mid, right sum: >=k and choose remain number of elements
        return mid*(1+mid)/2 + remain*(k+(k+remain-1))/2;
    }
};

/*
    Greedy

    n=3, k=5
    "last" denote the number to replace "the element which can be a pair", so it will start from n+1
    1, 2, 3, 4, 5, 6
   |_______|
    ^        ^
       ^        ^ => here '5' need to replace '3'
          ^        ^
    We will only accumulate [1...n], when elements can become pair, we need to fill the difference

    **BTW the maximum of "last" is k or n+1
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int ans=0, last=n+1;
        for (int i=1; i<=n; ++i) {
            ans+=i;
            int target=k-i;
            if (target>i) {
                if (target<=n) ans+=last-target;
                last++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minimumSum(int n, int k) {
        int ans=0, last=max(n+1, k);
        for (int i=1; i<=n; ++i) {
            ans+=i;
            int target=k-i;
            if (target>i && target<=n) ans+=last++-target;
        }
        return ans;
    }
};

/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int ans=0;
        for (int i=1; s.size()<n; ++i) {
            if (!s.count(k-i)) {
                s.insert(i);
                ans+=i;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int ans=0, ele=0;
        while (n) {
            ele++;
            if (s.count(k-ele)) continue;
            s.insert(ele);
            ans+=ele;
            n--;
        }
        return ans;
    }
};