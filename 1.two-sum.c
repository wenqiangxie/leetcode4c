/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9, returnSize = 0;

    int *output = twoSum(nums, 4, target, &returnSize);

    for (int ii = 0; ii < returnSize; ii++)
    {
        printf("%d\t", output[ii]);
    }

    return 0;
}

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    /* for every first number */
    for (int ii = 0; ii < numsSize - 1; ii++)
    {
        /* for every second number */
        for (int jj = ii + 1; jj < numsSize; jj++)
        {
            /* fetched target by first and second number */
            if (target == nums[ii] + nums[jj])
            {
                /* return number's index of answer */
                int *vec = (int *)malloc(2 * sizeof(int));

                vec[0] = ii;
                vec[1] = jj;

                *returnSize = 2;
                return vec;
            }
        }
    }

    /* not find any thing */
    returnSize = 0;
    return NULL;
}
// @lc code=end
