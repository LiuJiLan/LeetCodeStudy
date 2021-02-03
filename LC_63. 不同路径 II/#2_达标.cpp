//2020.11.14_#2_达标

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp = vector<int>(obstacleGrid.at(0).size(), 0);
        dp[dp.size() - 1] = 1;
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            for (int j = (int) obstacleGrid.at(0).size() - 1; j >= 0; j--) {
                if (obstacleGrid.at(i).at(j)) {
                    dp[j] = 0;
                    continue;
                }
                if (j < (int) obstacleGrid.at(0).size() - 1 && obstacleGrid.at(i).at(j + 1) != 1) {
                    //注意这里最好还是去掉对j + 1的判断
                    //因为每次都会多判断一次
                    //不如每次每次都 += dp[j + 1]
                    dp[j] += dp[j + 1];
                }
            }
        }
        return dp[0];
    }
};

//由于数据原因必须使用long防止溢出
#if 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> dp = vector<long>(obstacleGrid.at(0).size(), 0);
        dp[dp.size() - 1] = 1;
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            for (int j = (int) obstacleGrid.at(0).size() - 1; j >= 0; j--) {
                if (obstacleGrid.at(i).at(j)) {
                    dp[j] = 0;
                    continue;
                }
                if (j < (int) obstacleGrid.at(0).size() - 1 && obstacleGrid.at(i).at(j + 1) != 1) {
                    dp[j] += dp[j + 1];
                }
            }
        }
        return (int) dp[0];
    }
};
#endif
