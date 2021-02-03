//2020.10.06_#1_DFS思想

class Solution {
private:
    vector<string> ans;
    int SIZE;
    
    void DFS(string father, int left, int right) {
        if (right == SIZE) {  //只需要比较right,并不需要比较left,因为最后一项绝对是)
            ans.push_back(father);
            return;
        }
        
        string temp = string(father);
        
        if (left < SIZE) {
            DFS(temp + "(", left + 1, right);
        }
        if (right < left) {
            DFS(temp + ")", left, right + 1);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        ans = vector<string>();
        SIZE = n;
        string root = "";
        
        DFS(root, 0, 0);
        
        return ans;
    }
};
