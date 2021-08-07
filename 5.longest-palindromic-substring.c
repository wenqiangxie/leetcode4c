/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *longestPalindrome(char *s);

int main()
{
    char *s = "bcc";

    char *rs = longestPalindrome(s);

    printf("%s", rs);

    return 0;
}

// @lc code=start

/* test a substring with start and end index is palindrome string */
bool isPalindrome(char *s, int iStart, int iEnd)
{
    /* compare char from side to median in string */
    int ii = iStart, jj = iEnd;
    while (ii < jj)
    {
        if (s[ii] != s[jj])
        {
            return false;
        }

        ii++;
        jj--;
    }

    return true;
}

char *longestPalindrome(char *s)
{
    int max = 0, iStart = 0, iEnd = 0, ii, jj;

    /* create all possible substring and test for palindrome string */
    /* length less than max recorded substring isn't necessary, skip */
    for (ii = 0; ii < strlen(s); ii++)
    {
        for (jj = ii + max; jj < strlen(s); jj++)
        {
            if (isPalindrome(s, ii, jj))
            {
                if (jj - ii + 1 > max)
                {
                    max = jj - ii + 1;
                    iStart = ii;
                    iEnd = jj;
                }
            }
        }
    }

    /* create a new string to contain longest palindrome substring */
    char *str = (char *)calloc(jj - ii + 2, sizeof(char));
    for (int ii = 0; iStart + ii <= iEnd; ii++)
    {
        str[ii] = s[iStart + ii];
    }

    return str;
}
// @lc code=end
