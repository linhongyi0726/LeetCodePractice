// First time
/*
    [1, 0, 2, 3, 0, 4, 5, 0] -> [1, 0, 0, 2, 3, 0, 0, 4]
                          ^
    Here we only need to duplicate two zero, because the last zero will be removed
    And move backward to avoid the original element be overriden

    [1, 0, 2, 3, 0, 4, 5, 0|, 0, 0, 0] -> [1, 0, 2, 3, 0, 4, 5, 0|, 0, 0, 0]
                          ^         ^                     ^     ^
                          l         r                     l     r(skip one zero)
    *Note: The zero at the end of array need to skip
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size(), cnt=count(arr.begin(), arr.end(), 0);
        int l=n-1, r=n+cnt-1;
        while (l>=0 && r>=0) {
            if (arr[l]==0) {
                if (r<n) arr[r]=arr[l];
                // when r>=n, we need to skip those zero which l visited
                // It means they won't be duplicated
                --r;
            }
            if (r<n) arr[r]=arr[l];
            --r;
            --l;
        }
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size(), cnt=count(arr.begin(), arr.end(), 0);
        int l=n-1, r=n+cnt-1;
        for (; l>=0&&r>=0; --l,--r) {
            if (r<n) arr[r]=arr[l];
            if (arr[l]==0) {
                if (--r<n) arr[r]=arr[l];
            }
            /*
            if (r<n) arr[r]=arr[l];
            if (arr[l]==0 && --r<n) arr[r]=arr[l];
            */
        }
    }
};

/*
    Use another array
    T: O(n)/S: O(n)
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp;
        for (int n:arr) {
            if (n==0) tmp.push_back(n);
            tmp.push_back(n);
        }
        for (int i=0; i<arr.size(); ++i) arr[i]=tmp[i];
    }
};

/*
    Use insert or another loop to move remain element
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        for (int i=0; i<n; ++i) {
            if (arr[i]==0) {
                arr.insert(arr.begin()+i, 0);
                ++i;
            }
        }
        arr.resize(n);
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i]==0) {
                arr.pop_back();
                arr.insert(arr.begin()+i, 0);
                ++i;
            }
        }
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i]==0) {
                for (int j=arr.size()-1; j>i; --j) {
                    arr[j]=arr[j-1];
                }
                ++i;
            }
        }
    }
};