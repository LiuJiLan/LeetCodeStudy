//2020.12.06_#0_自己

#if 0
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]

normal: dp[index] += dp[index - 1]
#endif

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = vector<vector<int>>();
        vector<int> subAns = vector<int>();
        
        while (numRows-- > 0) {
            for (int i = (int) subAns.size() - 1; i > 0; i--) {
                subAns[i] += subAns[i - 1];
            }
            subAns.push_back(1);
            ans.push_back(subAns);
        }
        
        return ans;
    }
};

#if 0
//官方用了数学公式
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
#endif
