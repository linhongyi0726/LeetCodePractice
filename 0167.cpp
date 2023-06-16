// First time
/*
    Brute force
    T: O(n^2)/S: O(1)
    ---
    Optimize BF -> binary search (because of sorted array)
    Modify one for loop in BF to binary search
    T: O(nlogn)/S: O(1)
    ---
    Use hash map to store value:index (similar with problem 1)
    T: O(n)/S: O(n)
    ---
    Two pointer -> According problem description, there is exactly one solution
    T: O(n)/S: O(1)
    
    *Notice the return index need to +1 because of problem description
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;
        while (l<r) {
            if (numbers[l]+numbers[r]>target) r--;
            else if (numbers[l]+numbers[r]<target) l++;
            else return {l+1,r+1};
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        for (int i=0; i<numbers.size(); ++i) {
            if (mp.count(target-numbers[i]))
                return {mp[target-numbers[i]]+1, i+1};
            mp[numbers[i]]=i;
        }
        return {};
    }
};