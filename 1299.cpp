// First time
/*
    Go through the array backward and keep the maximum so for to change the element visited
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(), mx=-1;
        for (int i=n-1; i>=0; --i) {
            int tmp=arr[i];
            arr[i]=mx;
            mx=max(mx, tmp);
        }
        return arr;
    }
};

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(), mx=arr[n-1];
        for (int i=n-1; i>=0; --i) {
            int tmp=arr[i];
            if (i==n-1) arr[i]=-1;
            else arr[i]=mx;
            mx=max(mx, tmp);
        }
        return arr;
    }
};