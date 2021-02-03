//2020.10.16_#3_回溯

class Solution {
private:
    int MAX_NUM;
    int MAX_SIZE;
    vector<int> subAns;
    vector<vector<int>> ans;
    
    void recursion(int start) {
        if (subAns.size() == MAX_SIZE) {
            ans.push_back(subAns);
        }
        
        for (int i = start + 1; i <= MAX_NUM; i++) {
            subAns.push_back(i);
            recursion(i);
            subAns.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        MAX_NUM = n;
        MAX_SIZE = k;
        subAns = vector<int>();
        ans = vector<vector<int>>();
        
        recursion(0);
    
        return ans;
    }
};
