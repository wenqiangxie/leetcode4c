/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

int main()
{
    int nums1[] = {2}, nums2[] = {};
    double m = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));
    printf("%f", m);
    return 0;
}

// @lc code=start

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    /* nums1 and nums2 is sorted array, and we try to find median value of those arrays merged and sorted */
    /* so we make a virtual array which means nums1 and nums2 merged and vIndex is the lastest index of that */
    /* then try to add elements to virtual array from nums1 or nums2 one by one and keep sorted. */
    /* so iNums1 and iNums2 is the current index of nums1 and nums2, and num1 and num2 is last two element of virtual array, */
    /* and num1 < num2. */
    int vIndex = -1, iNums1 = 0, iNums2 = 0, num1, num2;

    /* we try to find median of virtual array, so we don't need get every elements but just half of all of them. */
    while (vIndex < (nums1Size + nums2Size) / 2)
    {
        /* a loop will append a new value to virtual merged array, so copy a new value from num2 to num1(num2 > num1)*/
        num1 = num2;
        /* the next value will from nums1 if: */
        /* all nums1 and nums2 have element and current value of nums1 less than nums2, or */
        /* just nums1 has element after current element. */
        /* and othewise of above tips, value will from num2 to virtual merged array */
        if ((iNums1 < nums1Size && iNums2 < nums2Size && nums1[iNums1] < nums2[iNums2]) || (iNums1 < nums1Size) && (iNums2 > nums2Size - 1))
        {
            /* append current nums1 value to virtual array and marked to num2 */
            num2 = nums1[iNums1];
            /* current index of nums1 move next */
            iNums1++;
        }
        else
        {
            /* append current nums2 value to virtual array and marked to num2 */
            num2 = nums2[iNums2];
            /* current index of nums2 move next */
            iNums2++;
        }

        /* count of virtual merged array add */
        vIndex++;
    }

    /* return median value of merged sorted array(virtual) */
    if ((nums1Size + nums2Size) % 2 == 0)
    {
        return (num1 + num2) / 2.0;
    }
    else
    {
        return num2;
    }
}
// @lc code=end
