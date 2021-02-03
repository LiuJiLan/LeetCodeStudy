//2020.11.05_#1_达标

//在官方解答上优化了一条条件语句
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
                if (j < obstacleGrid.at(0).size() - 1) {
                    singleLine[j] += singleLine[j + 1];
                }
            }
        }
        return singleLine[0];
    }
};

//由于数据原因必须使用long防止溢出
#if 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> singleLine = vector<long>(obstacleGrid.at(0).size(), 0);
        singleLine[singleLine.size() - 1] = 1;
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            for (int j = (int) obstacleGrid.at(0).size() - 1; j >= 0; j--) {
                if (obstacleGrid[i][j]) {
                    singleLine[j] = 0;
                    continue;
                }
                if (j < obstacleGrid.at(0).size() - 1) {
                    singleLine[j] += singleLine[j + 1];
                }
            }
        }
        return (int) singleLine[0];
    }
};
#endif
