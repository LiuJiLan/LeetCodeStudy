//2020.11.04_#-4_动态规划存单行

//问题,如果单行数组不用long会在
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
 * 原因:数据溢出
 * 更改类型后:通过
 **/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> singleLine = vector<long>(obstacleGrid[0].size(), 0);
        for (int i = (int) singleLine.size() - 1; i >= 0 ; i--) {
            if (obstacleGrid[obstacleGrid.size() - 1][i]) {
                break;
            }
            singleLine[i] = 1;
        }
        
        for (int i = (int) obstacleGrid.size() - 2; i >= 0; i--) {
            //这里写为(int i = (int) obstacleGrid.size() - 2; i >= 0; i--)
            //方便读取obstacleGrid的内容
            //注意计数次数是n - 1次
            if (obstacleGrid[i][obstacleGrid[0].size() - 1]) {
                singleLine[obstacleGrid[0].size() - 1] = 0;
            }
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

//溢出原因不明
#if 0
class Compare {
private:
    long max2;
    int max1;
    
    void show(vector<int> & array) {
        for (int i = 0; i < array.size(); i++) {
            max1 = max(array[i], max1);
            cout << array[i] << ",  ";
        }
        cout << "\n";
    }
    void show2(vector<long> & array) {
        for (int i = 0; i < array.size(); i++) {
            max2 = max(array[i], max2);
            cout << array[i] << ",  ";
        }
        cout << "\n";
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        max1 = 0;
        max2 = 0;
            
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
            show(f);
            cout << "\n\n";
        }
        
        cout << "-----------------------------\n";
        
        vector<long> singleLine = vector<long>(obstacleGrid[0].size(), 0);
        for (int i = (int) singleLine.size() - 1; i >= 0 ; i--) {
            if (obstacleGrid[obstacleGrid.size() - 1][i]) {
                break;
            }
            singleLine[i] = 1;
        }
        
        for (int i = (int) obstacleGrid.size() - 2; i >= 0; i--) {
            //这里写为(int i = (int) obstacleGrid.size() - 2; i >= 0; i--)
            //方便读取obstacleGrid的内容
            //注意计数次数是n - 1次
            if (obstacleGrid[i][obstacleGrid[0].size() - 1]) {
                singleLine[obstacleGrid[0].size() - 1] = 0;
            }
            for (int j = (int) singleLine.size() - 2; j >= 0 ; j--) {
                if (obstacleGrid[i][j]) {
                    singleLine[j] = 0;
                } else {
                    singleLine[j] += singleLine[j + 1];
                }
            }
            show2(singleLine);
            cout << "\n\n";
        }
        
        cout << max1 << "--" << max2 << endl;
        return (int) singleLine[0];

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
    Compare test;
    test.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
#endif
