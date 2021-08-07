/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main()
{
    int x = 121;

    int is = isPalindrome(x);

    true == is ? printf("true") : printf("false");

    return 0;
}

// @lc code=start

bool isPalindrome(int x)
{
    /* if number x is negative, it must not palindrome */
    if (x < 0)
    {
        return false;
    }

    /* try to reverse number x and marked as y */
    /* compare x and y should know x is or isn't palindrome */
    int y = 0, tx = x;

    while (tx > 0)
    {
        if (INT_MAX / 10 > y && (INT_MAX - y) > (tx % 10))
        {
            y = (y * 10) + (tx % 10);
            tx = tx / 10;
        }
        else
        {
            return false;
        }
    }

    /* compare number x and reverser number y, equal of them, */
    /*  x is palindrome, or not equal, not palindrome, and return */
    if (y == x)
        return true;
    else
        return false;
}
// @lc code=end
