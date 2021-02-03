//2020.11.04_#-4_动态规划全储存

class Solution {
private:
    vector<vector<int>> chessBoard;
    
    int dynamicProgrammingAndMemoryWhole(int i, int j) {
        if (i == chessBoard.size() || j == chessBoard[0].size()) {
            return 1;
        }
        
        if (chessBoard[i][j] == 0) {
            chessBoard[i][j] = dynamicProgrammingAndMemoryWhole(i + 1, j) + dynamicProgrammingAndMemoryWhole(i, j + 1);
        }
        
        return chessBoard[i][j];
    }
    
public:
    int uniquePaths(int m, int n) {
        chessBoard = vector<vector<int>>(m - 1, vector<int>(n - 1, 0));
        //为何dp算法是从点(0, 0)开始? (含义上从0, 0开始,如果使用其他方式底层实现另当别论)
        //因为dp的子问题是回答此点到终点的可能性
        //而自顶向下的思维是 m*n个格子的结果 = (m-1)*n个格子的结果 + m*(n-1)个格子的结果
        //
        //注意和63有障碍的棋盘的区别,在之前的自顶向下方法中(m-1)*n个格子棋盘 与 m*(n-1)个格子棋盘的 属性差别只在大小上
        //终止条件是当棋盘小到只有一行或1列
        //但如果有障碍不能这么考虑
        //有障碍的递归式子为 func(0, 0) = func(1, 0) + func(0 ,1)
        //func()含义为从参数点位置到终点位置的棋盘中的走法个数
        //这里的每个棋盘都有可能是不一样的,所以是从(0, 0)起点起步的
        //注意分清两者的区别。
        return dynamicProgrammingAndMemoryWhole(0, 0);
    }
};
