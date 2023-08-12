// First time
/*
    3 variable to trace maximum
    Use long because of the constraints of nums[i]
    or just use int and flag to check 3rd max exist or not
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;
        for (int num:nums) {
            if (num==max1 || num==max2 || num==max3) continue;
            if (num>max1) {
                max3=max2;
                max2=max1;
                max1=num;
            } else if (num>max2) {
                max3=max2;
                max2=num;
            } else if (num>max3) {
                max3=num;
            }
        }
        return max3==LONG_MIN?max1:max3;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;
        for (int num:nums) {
            if (num==max1 || num==max2 || num==max3) continue;
            if (num>max3) max3=num;
            if (num>max2) swap(max2, max3);
            if (num>max1) swap(max2, max1);
        }
        return max3==LONG_MIN?max1:max3;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        bool flag=false;
        for (int num:nums) {
            max1=max(max1, num);
        }
        for (int num:nums) {
            if (num!=max1) max2=max(max2, num);
        }
        for (int num:nums) {
            if (num!=max1 && num!=max2) {
                max3=max(max3, num);
                flag|=1;
            }
        }
        return flag?max3:max1;
    }
};

/*
    Use set
    The TC of set inserting and erasing is O(logk),
    but here k is constant (at most 4)
    T: O(n*log4 -> n)/S: O(1)
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int num:nums) {
            s.insert(num);
            if (s.size()>3) s.erase(s.begin());
        }
        if (s.size()==2) s.erase(s.begin());
        // if (s.size()==2) return *s.rbegin();
        return *s.begin();
    }
};

/*
    Use min heap
    T: O(n)/S: O(1) -> only need to store at most 4 elements
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> s;
        for (int num:nums) {
            if (!s.count(num)) pq.push(num);
            s.insert(num);
            if (pq.size()>3) {
                s.erase(pq.top());
                pq.pop();
            }
        }
        if (pq.size()==2) pq.pop();
        return pq.top();    // If size=1 or 3, just return pq.top()
    }
};

/*
    Use sorting
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans=nums[0], times=1;
        for (int num:nums) {
            if (num!=ans) {
                ans=num;
                times++;
            }
            if (times==3) return ans;
        }
        return nums[0];
    }
};