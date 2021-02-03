//2020.11.04_#-1_纯数学

//  纯数学,result应为long,避免越界
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        m--;
        n--;
        int N = m + n, M = min(m, n);
        long result = 1;
        for (int i = N - M + 1; i <= N; i++) {
            result *= i;
        }
        for (int i = 1; i <= M; i++) {
            result /= i;
        }
        return (int) result;
    }
};
