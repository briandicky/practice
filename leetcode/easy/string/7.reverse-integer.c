/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.42%)
 * Total Accepted:    354.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output:  321
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range. For the purpose of this problem,
 * assume that your function returns 0 when the reversed integer overflows.
 * 
 */
int reverse(int x) {
    int res = 0;

    while( x != 0 ) {
        // -2147483648 <= int <= 2147483647
        // INT_MAX = 2147483647
        // max res = 2147483641 or 2147483642
        // but 2463847412 is overflow
        if( abs(res) > (INT_MAX/10) )
            return 0;

        res = res * 10 + x % 10;
        x /= 10;
    }

    return res;
}
