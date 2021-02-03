//2020.11.04_#-5_动态规划存单行

/**
 * 报错
 * m = 1
 * n = 2
 * 原因,因为我省略了边界处始终为1的行或列
 * 解决方法在一开始加上一个判断
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        
        vector<int> singleLine = vector<int>(m - 1, 1);
        for (int i = 0; i < n - 1; i++) {
            singleLine[singleLine.size() - 1] += 1;
            for (int j = (int) singleLine.size() - 2; j >= 0 ; j--) {
                singleLine[j] += singleLine[j + 1];
            }
        }
        return singleLine[0];
    }
};
