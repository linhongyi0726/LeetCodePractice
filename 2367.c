// First time
/*
    Brute-force
    T: O(n^3)/S: O(1)
*/
int arithmeticTriplets(int* nums, int numsSize, int diff){
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 1; j < numsSize; j++) {
            for (int k = 2; k < numsSize; k++) {
                if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff))
                    ret++;
            }
        }
    }
    return ret;
}