//2020.11.22_#8_达标

class Solution {
private:
    int a, b;
    
    void drillDown(int level) {
        if (level <= 2) {
            return;
        }
        int temp = a;
        a = b;
        b += temp;
        drillDown(level - 1);
    }
    
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        a = 1;
        b = 2;
        drillDown(n);
        return b;
    }
};
