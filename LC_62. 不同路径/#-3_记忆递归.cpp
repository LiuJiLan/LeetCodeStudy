//2020.11.04_#-3_记忆递归

class Solution {
private:
    vector<vector<int>> chessBoard;
    
    int recursionAndMemory(int i, int j) {
        if (i == -1 || j == -1) {
            return 1;
        }
        
        if (chessBoard[i][j] == 0) {
            chessBoard[i][j] = recursionAndMemory(i - 1, j) + recursionAndMemory(i, j - 1);
        }
        
        return chessBoard[i][j];
    }
    
public:
    int uniquePaths(int m, int n) {
        chessBoard = vector<vector<int>>(m - 1, vector<int>(n - 1, 0));
        //  -1的原因,因为当m或n为1时直接返回1,没有必要初始化
        //  注意这里的赋值为1的意义是如果单行/单列的棋盘只有一种走法
        //  与DynamicProgramming中的赋值为1的意义是从点(m, n)倒退有几种走法
        //  -2的原因,在-1的基础上再-1是因为计算机中数组是由0为起点的
        //  全部值初始化为0的原因,因为现实问题中最小的值为1,所以赋0值以判断是否初始化过
        return recursionAndMemory(m - 2, n - 2);
    }
};
