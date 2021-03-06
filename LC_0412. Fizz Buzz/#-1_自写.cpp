//2021.02.13_#-1_自写

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans = vector<string>(n, "");
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                ans[i - 1] += "FizzBuzz";
                continue;
            }
            if (i % 3 == 0) {
                ans[i - 1] += "Fizz";
                continue;
            }
            if (i % 5 == 0) {
                ans[i - 1] += "Buzz";
                continue;
            }
            ans[i - 1] = to_string(i);
        }
        
        return ans;
    }
};
