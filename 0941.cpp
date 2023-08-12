// First time
/*
    Use two ptr or flag to check
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(), l=0, r=n-1;
        while (l+1<n && arr[l+1]>arr[l]) l++;
        while (r-1>=0 && arr[r-1]>arr[r]) r--;
        /*
        while (l<r && arr[l+1]>arr[l]) l++;
        while (l<r && arr[r-1]>arr[r]) r--;
        */
        return l==r && l!=0 && r!=n-1;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        bool up=false, down=false;
        for (int i=1; i<n; ++i) {
            if (!down && arr[i]>arr[i-1]) up=true;
            else if (up && arr[i]<arr[i-1]) down=true;
            else return false;
        }
        return up && down;
    }
};