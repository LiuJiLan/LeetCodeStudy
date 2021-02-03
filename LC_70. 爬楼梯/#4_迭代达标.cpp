//2020.09.16_#4_迭代达标

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }
        
        int a = 1;
        long int b = 2;//long int to avoid overflow
        while (--n > 0) {
            int temp = a;
            a = b;
            b = b + temp;
        }
        
        return a;
    }
};