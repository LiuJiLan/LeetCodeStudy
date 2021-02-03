//2020.11.04_#-1_死递归

/**
 * 错误用例
 * [[1]]
 * 原因:终点也是障碍点
 * 解决方案:如果终点是障碍直接返回0
 * violentRecursion只用来解决终点不是障碍的情况
 **/

/**
 * 错误用例
 * [
 * [0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0],
 * [0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0],
 * [1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1],
 * [0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
 * [0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
 * [0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0],
 * [0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0],
 * [1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0],
 * [0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0],
 * [0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0],
 * [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
 * [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0],
 * [0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0],
 * [0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0],
 * [0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1],
 * [0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0],
 * [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1],
 * [1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0],
 * [0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0],
 * [0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
 * [0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0],
 * [0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0],
 * [0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1],
 * [0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0],
 * [1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0],
 * [0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
 * [0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0],
 * [1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1],
 * [1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0]
 * ]
 * 原因:超出时间限制
 * 人工测试:通过
 **/
class Solution {
private:
    vector<vector<int>> * obstacleTable;
    
    int violentRecursion(int row, int column) {
        if (row == obstacleTable->size() - 1 && column == obstacleTable->at(0).size() - 1) {
            return 1;
        }
        if (obstacleTable->at(row).at(column) == 1) {
            return 0;
        }
        if (row == obstacleTable->size() - 1) {
            return violentRecursion(row, column + 1);
        }
        if (column == obstacleTable->at(0).size() - 1) {
            return violentRecursion(row + 1, column);
        }
        
        return violentRecursion(row, column + 1) + violentRecursion(row + 1, column);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) {
            return 0;
        }
        
        obstacleTable = & obstacleGrid;
        return violentRecursion(0, 0);
    }
};

#if 0

class Solution {
private:
    vector<vector<int>> * obstacleTable;
    
    int violentRecursion(int row, int column) {
        if (row == obstacleTable->size() - 1 && column == obstacleTable->at(0).size() - 1) {
            return 1;
        }
        if (obstacleTable->at(row).at(column) == 1) {
            return 0;
        }
        if (row == obstacleTable->size() - 1) {
            return violentRecursion(row, column + 1);
        }
        if (column == obstacleTable->at(0).size() - 1) {
            return violentRecursion(row + 1, column);
        }
        
        return violentRecursion(row, column + 1) + violentRecursion(row + 1, column);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) {
            return 0;
        }
        
        obstacleTable = & obstacleGrid;
        return violentRecursion(0, 0);
    }
};

class Compare {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = (int) obstacleGrid.size(), m = (int) obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
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

int main(int argc, const char * argv[]) {
    vector<vector<int>> obstacleGrid;
    obstacleGrid.push_back({0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0});
    obstacleGrid.push_back({1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1});
    obstacleGrid.push_back({0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0});
    obstacleGrid.push_back({0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0});
    obstacleGrid.push_back({1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0});
    obstacleGrid.push_back({0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0});
    obstacleGrid.push_back({0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0});
    obstacleGrid.push_back({0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0});
    obstacleGrid.push_back({0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1});
    obstacleGrid.push_back({0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1});
    obstacleGrid.push_back({1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0});
    obstacleGrid.push_back({0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0});
    obstacleGrid.push_back({0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0});
    obstacleGrid.push_back({0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0});
    obstacleGrid.push_back({0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1});
    obstacleGrid.push_back({0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0});
    obstacleGrid.push_back({1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0});
    obstacleGrid.push_back({0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0});
    obstacleGrid.push_back({1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1});
    obstacleGrid.push_back({1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0});
    
    Solution test;
    Compare compare;
    cout << test.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << compare.uniquePathsWithObstacles(obstacleGrid) << endl;
    
    return 0;
}

#endif
