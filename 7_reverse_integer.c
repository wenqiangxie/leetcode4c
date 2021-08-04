/**
 * 7. Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/
 *
 * Runtime: 4 ms, faster than 58.75% of C online submissions for Reverse Integer.
 * Memory Usage: 5.7 MB, less than 17.93% of C online submissions for Reverse Integer.
 */

int reverse(int x){
    int f = 1;
    if(x<0)
        f = -1;

    int y = 0;
    while(x != 0){
        int ty = x % 10;
        x = x / 10;
        if(f == 1 && INT_MAX / 10 >= y && INT_MAX - y * 10 > ty)
            y = y * 10 + ty;
        else if(f == -1 && INT_MIN / 10 <= y && INT_MIN - y * 10 < ty)
            y = y * 10 + ty;
        else
            return 0;
    }
    
    return y;
}
