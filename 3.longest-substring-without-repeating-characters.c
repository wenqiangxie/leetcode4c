/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char *s);

int main()
{
    char *s = "abcabcbb";
    int l = lengthOfLongestSubstring(s);
    printf("%d", l);
    return 0;
}

// @lc code=start

/* test a substring with start and end index has or hasn't repeat char */
int isRepeating(char *s, int iStart, int iEnd)
{
    for (int ii = iStart; ii < iEnd + 1; ii++)
    {
        for (int jj = ii + 1; jj < iEnd + 1; jj++)
        {
            if (s[ii] == s[jj])
                return true;
        }
    }

    return false;
}

int lengthOfLongestSubstring(char *s)
{
    /* max length of substring which without repeat char */
    int max = 0;

    /* generator all possible substring with two level loop */
    /* and in loop will try to skip some not necessary substring */
    /* outer loop is the start index of substring, and inner is the end index*/
    for (int ii = 0; ii < strlen(s); ii++)
    {
        /* if there are some repeat chart in start of substring, skip all of them*/
        while (ii + 1 < strlen(s) && s[ii] == s[ii + 1])
        {
            ii++;
        }

        /* try to test every char after start index be the end of substring */
        /* this problem try to find longest substring withou repeat, so */
        /* substring shorter than max substring has been recorded is not necessary, skip */
        for (int jj = ii + max; jj < strlen(s); jj++)
        {
            /* test substring marked by ii(start index) and jj(end index) has repeat char(s) */
            if (false == isRepeating(s, ii, jj))
            {
                /* this is a substring without repeat, just update max if it longer than recorded one */
                if (max < jj - ii + 1)
                    max = jj - ii + 1;
            }
            else
            {
                /* find a repeat substring, then substring which contain this substring is not necessary, skip */
                break;
            }
        }
    }

    return max;
}
// @lc code=end
