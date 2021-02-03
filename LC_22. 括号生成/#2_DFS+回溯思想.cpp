//2020.10.16_#2_DFS+回溯思想

class Solution {
private:
    int MAX_SIZE;
    string subAns;
    vector<string> ans;
    
    void DFS(int left, int right) {
        if (right == MAX_SIZE) {
            ans.push_back(subAns);
        }
        
        if (left < MAX_SIZE) {
            subAns.push_back('(');
            DFS(left + 1, right);
            subAns.pop_back();
        }
        
        if (right < left) {
            subAns.push_back(')');
            DFS(left, right + 1);
            subAns.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        MAX_SIZE = n;
        subAns = "";
        ans = vector<string>();
        DFS(0, 0);

        return ans;
    }
};
