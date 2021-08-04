/**
 * 1. Two Sum
 *
 * https://leetcode.com/problems/two-sum/
 *
 * Runtime: 80 ms, faster than 68.41% of C online submissions for Two Sum.
 * Memory Usage: 6.2 MB, less than 84.42% of C online submissions for Two Sum.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int ii = 0; ii < numsSize - 1; ii++){
        for(int jj = ii + 1; jj < numsSize; jj++){
            if(target == nums[ii] + nums[jj]){
                int *vec = (int *)malloc(2 * sizeof(int));
                
                vec[0] = ii;
                vec[1] = jj;

                *returnSize = 2;
                return vec;
            }
        }
    }
    
    returnSize = 0;
    return NULL;
}
