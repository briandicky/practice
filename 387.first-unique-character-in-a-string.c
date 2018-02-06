/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.27%)
 * Total Accepted:    101.1K
 * Total Submissions: 214.1K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

//#include <stdio.h>
//#include <stdlib.h>

int firstUniqChar(char* s) {
    int ch[256];
    int i;
    int index = -1;

    for( i = 0 ; i < 256 ; i++) 
        ch[i] = 0;

    for( i = 0 ; *(s+i) ; i++ ) 
        ++ch[(int)*(s+i)];
    
    for( i = 0 ; *(s+i) ; i++ ) {
        if( ch[(int)*(s+i)] == 1 ) {
            index = i;
            break;
        }
    }

    return index;
}

///* Driver program to test above function */
//int main(void) {
//    char str[] = "geeksforgeeks";
//    int index =  firstUniqChar(str);
//
//    if (index == -1)
//        printf("Either all characters are repeating or string is empty");
//    else
//        printf("First non-repeating character is %c", str[index]);
//
//    getchar();
//
//    return 0;
//}
