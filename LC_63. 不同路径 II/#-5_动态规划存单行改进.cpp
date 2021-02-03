//2020.11.04_#-5_动态规划存单行改进

//但是还是一定要long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> singleLine = vector<long>(obstacleGrid[0].size() + 1, 0);
        //将右曾添加一列虚拟的为0的列作为原来的墙壁,就可以省去特殊讨论
        for (int i = (int) singleLine.size() - 2; i >= 0 ; i--) {
            if (obstacleGrid[obstacleGrid.size() - 1][i]) {
                break;
            }
            singleLine[i] = 1;
        }
        
        for (int i = (int) obstacleGrid.size() - 2; i >= 0; i--) {
            for (int j = (int) singleLine.size() - 2; j >= 0 ; j--) {
                if (obstacleGrid[i][j]) {
                    singleLine[j] = 0;
                } else {
                    singleLine[j] += singleLine[j + 1];
                }
            }
        }
        
        return (int) singleLine[0];
    }
};

//依旧还是一定要long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> singleLine = vector<long>(obstacleGrid[0].size() + 1, 0);
        //将右曾添加一列虚拟的为0的列作为原来的墙壁,就可以省去特殊讨论
        
        singleLine[singleLine.size() - 2]
        = !obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            //从最底层开始做，假设是从底层的墙壁开始向上进行,注意要设一个终点的初值
            for (int j = (int) singleLine.size() - 2; j >= 0 ; j--) {
                if (obstacleGrid[i][j]) {
                    singleLine[j] = 0;
                } else {
                    singleLine[j] += singleLine[j + 1];
                }
            }
        }
        
        return (int) singleLine[0];
    }
};
