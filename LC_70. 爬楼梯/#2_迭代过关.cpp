//2020.09.11_#2_迭代过关

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2;
        
        if (n == 1) {
            return 1;
        }
        
        for (int i = 0; i < n - 2; i++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        
        return b;

    }
};