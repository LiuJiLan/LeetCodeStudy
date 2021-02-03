//2020.09.27_#2_8ms思路改版
class Solution {
private:
    vector<int> subAns;
    vector<vector<int>> ans;
    int MAX_NUM;
    int MAX_LEVEL;
    
    void recursion(int start) {
        if (subAns.size() == MAX_LEVEL) {
            ans.push_back(subAns);
            return;
        }
        
        for (int i = start + 1; i <= MAX_NUM; i++) {
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
        MAX_LEVEL = k;
        
        recursion(0);
        
        return ans;
    }
};

//第一次改进
/*
 class Solution {
 private:
     vector<int> subAns;
     vector<vector<int>> ans;
     int MAX_NUM;
     int MAX_LEVEL;
     
     void recursion(int start, int level) {
         if (level == MAX_LEVEL) {
             ans.push_back(subAns);
             return;
         }
         
         for (int i = start + 1; i <= MAX_NUM; i++) {
             subAns.push_back(i);
             recursion(i, level + 1);
             subAns.pop_back();
         }
     }
     
 public:
     vector<vector<int>> combine(int n, int k) {
         ans = vector<vector<int>>();
         subAns = vector<int>();
         MAX_NUM = n;
         MAX_LEVEL = k;
         
         recursion(0, 0);
         
         return ans;
     }
 };
 */
