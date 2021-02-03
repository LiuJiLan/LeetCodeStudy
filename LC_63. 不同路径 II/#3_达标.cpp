//2020.12.08_#3_达标

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> dp = vector<long>(obstacleGrid.at(0).size(), 0);
        dp[obstacleGrid.at(0).size() - 1] = 1;
        
        for (int row = (int) obstacleGrid.size() - 1; row >= 0; row--) {
            for (int column = (int) obstacleGrid.at(0).size() - 1; column >= 0; column--) {
                if (obstacleGrid.at(row).at(column) == 1) {
                    dp[column] = 0;
                    continue;
                }
                if (column < obstacleGrid.at(0).size() - 1) {
                    dp[column] += dp[column + 1];
                }
            }
        }
        
        return (int) dp[0];
    }
};
