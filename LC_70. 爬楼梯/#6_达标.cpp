//2020.10.07_#6_达标

class Solution {
private:
    int a;
    int b;
    
    void recursion(int level) {
        if (level == 2) {
            return;
        }
        
        int temp = a;
        a = b;
        b = b + temp;
        
        recursion(level - 1);
    }
    
    
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        a = 1;
        b = 2;
        
        recursion(n);
        
        return b;
    }
};
