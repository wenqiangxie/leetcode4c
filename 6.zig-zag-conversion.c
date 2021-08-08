/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *convert(char *s, int numRows);

int main()
{
    char *s = "PAYPALISHIRING";
    int numRows = 3;

    char *r = convert(s, numRows);
    printf("%s", r);

    return 0;
}

// @lc code=start

/* just need char but not space and newline */
char *convert(char *s, int numRows)
{
    /* return input string if just need convert one line */
    if (numRows == 1)
    {
        return s;
    }

    int groupCapacity = 2 * numRows - 2;
    int groupNumber = (int)ceil(strlen(s) / (double)groupCapacity);
    int groupColumn = numRows - 1;

    /* new string and index of that */
    char *str = (char *)calloc(strlen(s) + 1, sizeof(char));
    int iStr = 0;

    for (int rr = 0; rr < numRows; rr++)
    {
        for (int gg = 0; gg < groupNumber; gg++)
        {
            /* first char of a group in a line */
            if (rr + gg * groupCapacity < strlen(s))
            {
                str[iStr++] = s[rr + gg * groupCapacity];
            }

            /* second char of a group in a line */
            if (rr != 0 && rr != numRows - 1)
            {
                int idx = (gg + 1) * groupCapacity - rr;
                if (idx > -1 && idx < strlen(s))
                {
                    str[iStr++] = s[(gg + 1) * groupCapacity - rr];
                }
            }
        }
    }

    return str;
}
// @lc code=end
