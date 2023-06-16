// First time
/*
    Brute-force
    T: O(N^2)/S: O(1)
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    *returnSize = 2;
    int *returnValue = malloc((*returnSize)*sizeof(int));
    for (i=0; i<numsSize; i++)
    {
        for (j=i+1; j<numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnValue[0] = i;
                returnValue[1] = j;
            }
        }
    }
    return returnValue;
}