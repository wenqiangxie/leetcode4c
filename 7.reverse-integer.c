/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

#include <stdio.h>
#include <limits.h>

int reverse(int x);

int main()
{
    int x = 123;

    int y = reverse(x);
    printf("%d", y);

    return 0;
}

// @lc code=start

int reverse(int x)
{
    /* flag of number x(negative or not)*/
    int f = 1;
    if (x < 0)
    {
        f = -1;
    }
    /* new result marked as y */
    int y = 0;
    /* try to reverse number x */
    while (x != 0)
    {
        /* last digit of x marked as ty */
        int ty = x % 10;
        /* remain value of x */
        x = x / 10;
        /* try to add ty to y, and can't out of the range of 32 bit int */
        if (f == 1 && INT_MAX / 10 >= y && INT_MAX - y * 10 > ty)
            y = y * 10 + ty;
        else if (f == -1 && INT_MIN / 10 <= y && INT_MIN - y * 10 < ty)
            y = y * 10 + ty;
        else
            return 0;
    }

    /* return result */
    return y;
}
// @lc code=end
