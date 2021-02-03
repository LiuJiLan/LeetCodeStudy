//2020.11.14_#4_达标

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> subAns;
    int MAX_NUM;
    int MAX_LENGHT;
    
    void recursion(int startNumber) {
        if (subAns.size() == MAX_LENGHT) {
            ans.push_back(subAns);
            return;
        }
        
        for (int i = startNumber + 1; i <= MAX_NUM; i++) {
            subAns.push_back(i);
            recursion(i);
            subAns.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        ans = vector<vector<int>>();
        subAns = vector<int>();
        MAX_NUM = n;
        MAX_LENGHT = k;
        recursion(0);
        return ans;
    }
};
