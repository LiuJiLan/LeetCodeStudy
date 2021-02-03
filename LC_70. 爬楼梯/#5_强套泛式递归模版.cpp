//2020.09.16_#5_强套泛式递归模版

class Solution {
private:
    int a, b;
    
    void recursion(int level) {
        if (level <= 2) {
            return ;
        }
        
        int temp = a;
        a = b;
        b = b + temp;
        
        recursion(level - 1);
    }
    
public:
    int climbStairs(int n) {
        a = 1;
        b = 2;
        
        if (n <= 1) {
            return a;
        } else if (n == 2) {
            return b;
        } else {
            recursion(n);
            return b;
        }
        
    }
};


/*
 // C/C++
 void recursion(int level, int param) {
   // recursion terminator
   if (level > MAX_LEVEL) {
     // process result
     return ;
   }

   // process current logic
   process(level, param);

   // drill down
   recursion(level + 1, param);

   // reverse the current level status if needed
 }
 */
