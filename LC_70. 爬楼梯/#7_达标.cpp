//2020.11.01_#7_达标

class Solution {
private:
    int a, b;
    
    void recursion(int count) {
        if (count == 2) {
            return;
        }
        int temp = a;
        a = b;
        b += temp;
        recursion(--count);
    }
    
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        
        a = 1;
        b = 2;
        recursion(n);
        return b;
    }
};
