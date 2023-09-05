// First time
/*
    Power by 2 -> bit
    Check from small to big -> Greedy

    Record all of bits of nums used, then check does target need those bits or not
    If there are 2 the same bits, they can combine to 1 next bit
    -> Can be used for next loop to check

    *Notice we only need to keep minimum lacking bit,
    because when we divide bigger number by 2, it will cover all of the bits less then it
    ex. lack: 2(bit 1), 4(bit 2); current: 8(bit 3) -> 8 divide to 2 will also cover 4

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> cnt(32, 0);
        int ret = 0, lack = 32;
        for (int num : nums) ++cnt[log2(num)];
        // Because of the constraints: 1 <= target < 2^31
        // for (int i = 0; i < 31; ++i) {
        for (int i = 0; i < cnt.size(); ++i) {
            if (target & (1 << i)) {
                if (cnt[i]) --cnt[i];
                else lack = min(lack, i);
            }
            if (cnt[i] && lack < i) {
                --cnt[i];
                ret += i - lack;
                lack = 32;
            }
            // cnt[i + 1] += (cnt[i] >> 1);
            if (i != 31) cnt[i + 1] += (cnt[i] >> 1);
        }
        return lack != 32 ? -1 : ret;
    }
};

/*
    Choose the number from big to small
    T: O(nlogn)/ S: O(nlogn)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        if (sum < target) return -1;
        sort(nums.begin(), nums.end());
        int ret = 0;
        while (target) {
            int mx = nums.back();
            nums.pop_back();
            if (sum - mx >= target) {   // Not need to sum together
                sum -= mx;
            } else if (mx <= target) {  // Need to sum together and can't be broke
                sum -= mx;
                target -= mx;
            } else {    // Need to sum together and need to break
                nums.push_back(mx >> 1);
                nums.push_back(mx >> 1);
                ret += 1;
            }
        }
        return ret;
    }
};