//2020.11.14_#2_达标

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp = vector<int>(m, 0);
        dp[dp.size() - 1] = 1;
        for (int i = n; i > 0; i--) {
            for (int j = (int) dp.size() - 2; j >= 0; j--) {
                dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};
