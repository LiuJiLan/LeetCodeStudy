//2020.11.04_#-2_记忆递归

class Solution {
private:
    vector<vector<int>> * obstacleTable;
    vector<vector<int>> chessBoard;
    
    int recursionAndMemory(int row, int column) {
        if (row == obstacleTable->size() - 1 && column == obstacleTable->at(0).size() - 1) {
            return 1;
        }
        if (obstacleTable->at(row).at(column) == 1) {
            return 0;
        }
        if (row == obstacleTable->size() - 1) {
            return recursionAndMemory(row, column + 1);
        }
        if (column == obstacleTable->at(0).size() - 1) {
            return recursionAndMemory(row + 1, column);
        }
        
        if (chessBoard.at(row).at(column) == 0) {
            chessBoard[row][column]
            = recursionAndMemory(row, column + 1) + recursionAndMemory(row + 1, column);
        }
        
        return chessBoard[row][column];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) {
            return 0;
        }
        chessBoard
        = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        obstacleTable = & obstacleGrid;
        return recursionAndMemory(0, 0);
    }
};

//有关recursionAndMemory(0, 0);参数的含义
//递归方程: func(点(n, m)为起点的棋盘)
// = func(点(n + 1, m)为起点的棋盘) + func(点(n, m + 1)为起点的棋盘)
// [注意当为最右列或者最底层行的特殊情况,这里不做书写]
//
//为什么在uniquePathsWithObstacles中直接设置条件来讨论点(max_Row, max_Column)不是冗余的?
//首先,如果终点有障碍,可以直接判断永远到不了终点。
//其次,每次的递归子问题都是可以包含点(max_Row, max_Column)的子棋盘。
//这意味着如果将点(max_Row, max_Column)写入通式相当于每次调用都得到0 + 0 = 0
//
//更重要的是:
//这会导致递归函数中:
#if 0
if (row == obstacleTable->size() - 1 && column == obstacleTable->at(0).size() - 1 && obstacleTable->at(obstacleTable->size() - 1).at(obstacleTable->at(0).size() - 1) != 1) {
    return 1;
} else / else if (...) {
    ...
}
#endif
//或
#if 0
if (obstacleTable->at(obstacleTable->size() - 1).at(obstacleTable->at(0).size() - 1) == 1) {
    return 0;
}
if (row == obstacleTable->size() - 1 && column == obstacleTable->at(0).size() - 1) {
    return 1;
}
#endif
//那么,
#if 0
Time(点(max_Row, max_Column)不写入通式) => {
    = 1; (如果(max_Row, max_Column)是障碍)
    = O(...); (如果(max_Row, max_Column)不是障碍)
}

Time(点(max_Row, max_Column)写入通式) => {
    >= O(...); (如果(max_Row, max_Column)是障碍) [极端条件下可以退化成=号(如果除了起点都是障碍就是其中一种情况)]
    >= O(...); (如果(max_Row, max_Column)不是障碍) [极端条件下可以退化成=号(如果除了起点和终点都是障碍就是其中一种情况)]
}
#endif
//平均时长被拉长了
