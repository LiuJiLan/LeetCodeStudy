//2020.12.08_#3_达标

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp = vector<int>(m, 0);
        dp[m - 1] = 1;
        
        for (int row = n - 1; row >= 0; row--) {
            for (int column = m - 2; column >= 0; column--) {
                dp[column] += dp[column + 1];
            }
        }
        
        return dp[0];
    }
};
