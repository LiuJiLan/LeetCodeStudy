//2020.11.04_#0_MostVotes

//MostVotes_Java
//本质是正向推
//本质是回答如何从终点回到起点
#if 0
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int width = obstacleGrid[0].length;
    int[] dp = new int[width];
    dp[0] = 1;
    for (int[] row : obstacleGrid) {
        for (int j = 0; j < width; j++) {
            if (row[j] == 1)
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp[width - 1];
}
#endif

#if 0
//[[0,0,0,0,0,0,0,0,0],[0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0,0],[1,0,0,1,0,1,0,0,0]]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int width = (int) obstacleGrid[0].size();
        vector<int> dp = vector<int>(width, 0);
        dp[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < width; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[width - 1];
    }
};
#endif

//官方解答_C++
//也是从(0, 0)推导到(m, n)
#if 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f = vector<int>(m);

        f[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};
#endif

//倒着推理必溢出
#if 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> singleLine = vector<int>(obstacleGrid.at(0).size(), 0);
        singleLine[singleLine.size() - 1] = 1;
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            for (int j = (int) obstacleGrid.at(0).size() - 1; j >= 0; j--) {
                if (obstacleGrid[i][j]) {
                    singleLine[j] = 0;
                    continue;
                }
                if (j < obstacleGrid.at(0).size() - 1 && obstacleGrid[i][j + 1] != 1) {
                    singleLine[j] += singleLine[j + 1];
                }
            }
        }
        return singleLine[0];
    }
};
#endif
