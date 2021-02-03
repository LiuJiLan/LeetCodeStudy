//2020.11.14_#3_达标

class Solution {
private:
    vector<string> ans;
    string subAns;
    int MAX_LEVEL;
    
    void recursion(int l, int r) {
        if (subAns.length() == 2 * MAX_LEVEL) {
            ans.push_back(subAns);
            return;
        }
        
        if (l < MAX_LEVEL) {
            subAns.push_back('(');
            recursion(l + 1, r);
            subAns.pop_back();
        }
        if (r < l) {
            subAns.push_back(')');
            recursion(l, r + 1);
            subAns.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        ans = vector<string>();
        subAns = "";
        MAX_LEVEL = n;
        recursion(0, 0);
        return ans;
    }
};
