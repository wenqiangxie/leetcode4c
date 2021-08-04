/**
 * 9. Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/
 *
 * Runtime: 4 ms, faster than 92.06% of C online submissions for Palindrome Number.
 * Memory Usage: 5.9 MB, less than 73.91% of C online submissions for Palindrome Number.
 */

bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    
    int y = 0, tx = x;
    
    while(tx > 0){
        if(INT_MAX / 10 > y && (INT_MAX - y) > (tx % 10)){
            y = (y * 10) + (tx % 10);
            tx = tx / 10;
        }else{
            return false;
        }
        
    }
    
    if(y == x)
        return true;
    else
        return false;
}
