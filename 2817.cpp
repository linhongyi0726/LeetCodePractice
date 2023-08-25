// First time
/*
    Use set instead of multiset because we insert nums[i-x], so the elements in set are nums[0...n-x-1]
    Elements which index > i will satisfy the requirement with all the elements already in the set,
    so we don't need to erase any element like using multiset, and its index is not matter
    [5, 3, 3, 2, 10, 15], x=2
    |_|    ^
    |____|    ^
    |_______|     ^
    -> if nums[i]=10, [5,3] are all satisfied no matter which 3's index is,
        because we just need to return the difference

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size(), ans=INT_MAX;
        set<int> s;
        for (int i=x; i<n; ++i) {
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if (it!=s.end()) ans=min(ans, abs(nums[i]-*it));
            if (it!=s.begin()) ans=min(ans, abs(nums[i]-*prev(it)));
        }
        return ans;
    }
};

/*
    [5, 3, 2, 10, 15], x=2
          |_________|
    The elements in set are nums[x...n-1], means the possible elements that can pair with nums[0...x-1]
    *Notice we need to check *prev(it) because the absolute of them may smaller
    ex. lower_bound(5) -> 10, but abs(5-2) is smaller

    After checking, we need to erase nums[i+x]
    because if i++, this element in multiset will not be satisfied
    -> That is why we need to use multiset, we need the same element because their index is different

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size(), ans=INT_MAX;
        multiset<int> ms;
        for (int i=x; i<n; ++i) ms.insert(nums[i]);
        for (int i=0; i<n-x; ++i) {
            auto it=ms.lower_bound(nums[i]);    // find the smallest >= nums[i] element
            if (it!=ms.end()) ans=min(ans, abs(nums[i]-*it));
            if (it!=ms.begin()) ans=min(ans, abs(nums[i]-*prev(it)));
            ms.erase(ms.find(nums[i+x]));
        }
        return ans;
    }
};