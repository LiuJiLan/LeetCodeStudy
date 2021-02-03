// #1_2020.09.07
// 这是我做的第一道LeetCode题,
// 本身是用C语言写的.


#if 0

//
//  main.c
//  LeetCode_125_C
//
//  Created by 刘冬辰 on 2020/9/7.
//  Copyright © 2020 刘冬辰. All rights reserved.
//

//#1_2020.09.07



/*
 125. 验证回文串
 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

 说明：本题中，我们将空字符串定义为有效的回文串。

 示例 1:

 输入: "A man, a plan, a canal: Panama"
 输出: true
 示例 2:

 输入: "race a car"
 输出: false
 */

/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 Note: For the purpose of this problem, we define empty string as valid palindrome.

 Example 1:

 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:

 Input: "race a car"
 Output: false
  

 Constraints:

 s consists only of printable ASCII characters.
 */


/*
 bool isPalindrome(char * s){

 }
 */

/*
 bool isPalindrome(string s) {
     for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
         while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
         while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
         if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
     }
     
     return true;
 }
*/

#include <stdio.h>
#include <string.h>

int isPalindrome(char * s);
int isAlaphNum(char ch);
char toLower(char ch);

int main(int argc, const char * argv[]) {
    
    char * str1 = "A man, a plan, a canal: Panama";
    char * str2 = "race a car";

    if (isPalindrome(str1)) {
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    
    if (isPalindrome(str2)) {
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    
    return 0;
}

int isPalindrome(char * s){
    int i,j;
    
    for (i=0,j=(int)strlen(s)-1; i<j; i++,j--) {
        
        while (!isAlaphNum(s[i]) && i<j) {
            i++;
        }
        
        while (!isAlaphNum(s[j]) && i<j) {
            j--;
        }
        
        if (toLower(s[i])!=toLower(s[j])) {
            return 0;
        }
        
    }
    
    return 1;
}

int isAlaphNum(char ch) {
    if ((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
        return 1;
    }
    else {
        return 0;
    }
}

char toLower(char ch) {
    if(ch>='A' && ch<='Z') {
        return ch+32;
    }
    
    return ch;
}


/*
 LeetCode无法通过，本质上是因为函数的声明一定要在主函数前面，不能用分段的方式把子函数插入进去。
 自己研发新语言时，可以将函数绑定到一个block中（类似于class但没有继承之类的）
 */

#endif
