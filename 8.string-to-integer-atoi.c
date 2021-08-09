/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

#include <stdio.h>
#include <limits.h>

int myAtoi(char *s);

int main()
{
    char *s = "2147483648";

    int r = myAtoi(s);

    printf("%d", r);

    return 0;
}

// @lc code=start

int myAtoi(char *s)
{
    char *ps = s;

    int negative = 1;
    int r = 0, t;
    int inNumber = 0;

    while (*ps != '\0')
    {
        if (inNumber == 0 && *ps == ' ')
        {
            /* lead in whitespace, do nothing and move next character */
            // printf("lead in whitespace, to next\n");
        }
        else if (inNumber == 0 && *ps == '-')
        {
            // printf("got a negative flag.\n");
            negative = -1; // marked as a negative number
            inNumber = 1;  // marked a number has been got
        }
        else if (inNumber == 0 && *ps == '+')
        {
            negative = 1; // marked as a positive number
            inNumber = 1; // marked a number has been got
        }
        else if (*ps >= '0' && *ps <= '9')
        {
            /* got a figure character */
            inNumber = 1;  // marked it a number got
            t = *ps - '0'; // cover current character to number

            /* positive number out of range when add next figure to result */
            if (r >= 0 && r > (INT_MAX / 10))
                return INT_MAX;
            if (r >= 0 && r == (INT_MAX / 10) && t > 7)
                return INT_MAX;

            /* negative number out of range when add next figure to result */
            if (r < 0 && r < (INT_MIN / 10))
                return INT_MIN;
            if (r < 0 && r == (INT_MIN / 10) && t > 8)
                return INT_MIN;

            if (negative == -1 && r == 0)
            {
                /* negative number first figure */
                r = -1 * t;
            }
            else
            {
                /* add figure to number */
                r = r * 10 + negative * t;
            }
        }
        else
        {
            /* other character not figure or leading whitespace, stop process */
            break;
        }

        ps++;
    }

    return r;
}
// @lc code=end
