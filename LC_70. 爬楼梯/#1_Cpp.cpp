//2020.09.09

class Solution {
public:
    int climbStairs(int n) {
        return fib(2,1,n);
    }

private:
    int fib (int a, int b, int n) {
        if (n == 1) {
            return b;
        }
        else if (n == 2) {
            return a;
        }
        else {
            return fib(a+b, a, n-1);
        }
    }
};

//原题
/*
class Solution {
public:
    int climbStairs(int n) {

    }
};

*/

//#1 不用递归
/*
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }
        else {
            int  a = 1 ,b = 2 ;
            
            for (int i = 3;i <= n;i++) {
                int temp = b;
                b = a + b;
                a = temp;
            }
            return b;
        }
    }
};
*/