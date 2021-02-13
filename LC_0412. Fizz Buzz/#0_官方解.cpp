//2021.02.13_#0_官方解

// 我也想到了用加法, 但是没想出来怎么处理数字
// 官方解处理纯数字项的方法确实很巧妙

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans = vector<string>(n, "");
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0) {
                ans[i] += "Fizz";
            }
            if ((i + 1) % 5 == 0) {
                ans[i] += "Buzz";
            }
            if (ans[i] == "") {
                ans[i] = to_string(i + 1);
            }
        }
        
        return ans;
    }
};
