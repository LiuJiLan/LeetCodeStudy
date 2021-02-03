//2020.11.05_#1_达标

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> singleLine = vector<int>(m);
        singleLine[m - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                // j = m - 2,因为最右边一定都是1
                singleLine[j] += singleLine[j + 1];
            }
        }
        return singleLine[0];
    }
};
