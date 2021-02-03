//2020.09.11_#3_尾递归过关

class Solution {
public:
    int climbStairs(int n) {
        return fib(1, 2, n);
    }
    
    int fib(int a, int b, int count) {
        if (count == 1) {
            return a;
        }
        else if (count == 2) {
            return b;
        }
        else {
            return fib(b, a+b , count-1);
        }
        
        
    }
};