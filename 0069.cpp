// First time
/*
    Binary search
    *Notice the edge and condition of l and r
    Here return r because when we end loop, it will be l>r and we want the smaller number
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        if (!x) return x;
        int l=1, r=x;
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (mid==x/mid) return mid;
            else if (mid>x/mid) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        while (l<=r) {
            long mid=(l+r)/2;
            if (mid*mid==x) return mid;
            else if (mid*mid>x) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};

/*
    If we use [left, right) condition, it will end loop when l==r so we need to return l-1 (or r-1)
    -> but need to handle x=0
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return x;
        long l=0, r=(long)x+1;
        while (l<r) {
            long mid=(r+l)/2;
            if (mid*mid==x) return mid;
            else if (mid*mid>x) r=mid;
            else l=mid+1;
        }
        return l-1;
    }
};

/*
    Newton's method
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        long ans = x;
        while (ans*ans > x) {
            ans = (ans + x/ans)/2;
        }
        return ans;
    }
};