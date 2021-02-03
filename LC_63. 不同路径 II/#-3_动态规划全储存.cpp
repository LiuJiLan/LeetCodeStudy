//2020.11.04_#-3_动态规划全储存

class Solution {
private:
    vector<vector<int>> * obstacleTable;
    vector<vector<int>> chessBoard;
    
    int dynamicProgrammingAndMemoryWhole(int i, int j) {
        if (obstacleTable->at(i).at(j) == 1) {
            return 0;
        }
        if (i < obstacleTable->size() - 1 &&
            j < obstacleTable->at(0).size() - 1 &&
            chessBoard.at(i).at(j) == 0) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i, j + 1)
            + dynamicProgrammingAndMemoryWhole(i + 1, j);
        }
        return chessBoard[i][j];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        chessBoard
        = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < obstacleGrid[0].size(); i++) {
            chessBoard[obstacleGrid.size() - 1][i] = 1;
        }
        for (int i = 0; i < obstacleGrid.size(); i++) {
            chessBoard[i][obstacleGrid[0].size() - 1] = 1;
        }
        
        int indexOfTheLastObstacleInLastRow = -1;
        for (int i = (int) obstacleGrid[0].size() - 1; i >= 0; i--) {
            if (obstacleGrid[obstacleGrid.size() - 1][i] == 1) {
                indexOfTheLastObstacleInLastRow = i;
                break;
            }
        }
        int indexOfTheLastObstacleInLastColumn = -1;
        for (int i = (int) obstacleGrid.size() - 1; i >= 0; i--) {
            if (obstacleGrid[i][obstacleGrid[0].size() - 1] == 1) {
                indexOfTheLastObstacleInLastColumn = i;
                break;
            }
        }
        
        if (indexOfTheLastObstacleInLastRow >= 0) {
            for (int i = 0; i <= indexOfTheLastObstacleInLastRow; i++) {
                chessBoard[obstacleGrid.size() - 1][i] = 0;
            }
        }
        if (indexOfTheLastObstacleInLastColumn >= 0) {
            for (int i = 0; i <= indexOfTheLastObstacleInLastColumn; i++) {
                chessBoard[i][obstacleGrid[0].size() - 1] = 0;
            }
        }
        
        obstacleTable = & obstacleGrid;
        return dynamicProgrammingAndMemoryWhole(0, 0);
    }
};

//虽然从书写过程上 动态规划全储存 与 记忆递归 的思维相同
//但是采取的方法是先赋最下面一行和最后一列初值在处理的思维
//从效率角度是应该在uniquePathsWithObstacles中就考虑
//(max_Row, max_Column)是否为障碍这一情况,
//但是从逻辑上这是冗余的。
//在这种思想下每个点都是平等的,
//事实上即使是最下面一行和最后一列都属于一般情况,
//只不过是因为有一面靠壁,所以只用累加上一边。
//事实上,先赋最下面一行和最后一列初值都是不符合全局逻辑的,
//只能看作一种优化处理,所以在这种情况下,以上的写法属于:
//优化不彻底,逻辑不具有普遍性的写法
//
//以下是更通式逻辑的写法
#if 0
class Solution {
private:
    vector<vector<int>> * obstacleTable;
    vector<vector<int>> chessBoard;
    
    int dynamicProgrammingAndMemoryWhole(int i, int j) {
        if (obstacleTable->at(i).at(j) == 1) {
            return 0;
        }
        
        if (i == obstacleTable->size() - 1 &&
            j == obstacleTable->at(0).size() - 1) {
            return (int) !obstacleTable->at(i).at(j);
        }
        if (i == obstacleTable->size() - 1) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i, j + 1);
        }
        if (j == obstacleTable->at(0).size() - 1) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i + 1, j);
        }
        
        if (i < obstacleTable->size() - 1 &&
            j < obstacleTable->at(0).size() - 1 &&
            chessBoard.at(i).at(j) == 0) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i, j + 1)
            + dynamicProgrammingAndMemoryWhole(i + 1, j);
        }
        
        return chessBoard[i][j];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        chessBoard
        = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        obstacleTable = & obstacleGrid;
        return dynamicProgrammingAndMemoryWhole(0, 0);
    }
};
#endif
//将算法化为通式后,从逻辑角度就应该在uniquePathsWithObstacles中就考虑
//(max_Row, max_Column)是否为障碍这一情况。
//因为在上一种写法中,
//最下面一行和最后一列初值是由indexOfTheLastObstacleInLastRow 与
//indexOfTheLastObstacleInLastColumn决定的,
//此时的(max_Row, max_Column)是否为障碍这一情况包含于
//indexOfTheLastObstacleInLastRow 与 indexOfTheLastObstacleInLastColumn
//的决定权中。
//但如果化为通式会发现,
//如果将最下面一行和最后一列初看作稍微特殊,
//(max_Row, max_Column)将是最特殊的,
//其他的格子都是普通格。
//在这个思维下,最下面一行和最后一列的值都由(max_Row, max_Column)决定,
//其他格子的值都由最下面一行和最后一列的值决定,
//所以可以得出(max_Row, max_Column)可以决定所有格子的值,
//即(max_Row, max_Column)是所有子问题的公共最终子问题。
//所以,从逻辑角度就应该在uniquePathsWithObstacles中就考虑它是合理的。
//
//所以有:
#if 0
class Solution {
private:
    vector<vector<int>> * obstacleTable;
    vector<vector<int>> chessBoard;
    
    int dynamicProgrammingAndMemoryWhole(int i, int j) {
        if (obstacleTable->at(i).at(j) == 1) {
            return 0;
        }
        
        if (i == obstacleTable->size() - 1 &&
            j == obstacleTable->at(0).size() - 1) {
            return 1;
        }
        if (i == obstacleTable->size() - 1) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i, j + 1);
        }
        if (j == obstacleTable->at(0).size() - 1) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i + 1, j);
        }
        
        if (i < obstacleTable->size() - 1 &&
            j < obstacleTable->at(0).size() - 1 &&
            chessBoard.at(i).at(j) == 0) {
            chessBoard[i][j]
            = dynamicProgrammingAndMemoryWhole(i, j + 1)
            + dynamicProgrammingAndMemoryWhole(i + 1, j);
        }
        
        return chessBoard[i][j];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) {
            return 0;
        }
        chessBoard
        = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        obstacleTable = & obstacleGrid;
        return dynamicProgrammingAndMemoryWhole(0, 0);
    }
};
#endif
