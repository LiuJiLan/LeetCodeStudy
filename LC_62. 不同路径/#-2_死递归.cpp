//2020.11.04_#-2_死递归

/**
 * 超时时限
 * m = 51
 * n = 9
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

