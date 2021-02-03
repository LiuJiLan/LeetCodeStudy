//2020.09.27_#1_自己套泛式递归
class Solution {
private:
    vector<vector<int>> ans;
    int MAX_NUM;
    int MAX_LEVEL;
    
    void recursion(vector<int> father, int start, int level) {
        if (level == MAX_LEVEL) {
            ans.push_back(father);
            return;
        }
        
        for (int i = start + 1; i <= MAX_NUM; i++) {
            vector<int> fatherCopy = vector<int>(father);
            fatherCopy.push_back(i);
            recursion(fatherCopy, i, level + 1);
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        ans = vector<vector<int>>();
        MAX_NUM = n;
        MAX_LEVEL = k;
        
        recursion(vector<int>(), 0, 0);
        
        return ans;
    }
};


//8ms代码
/*
 class Solution {
 public:
     vector<vector<int>> combine(int n, int k) {
         helper(1, n, k);
         return result_;
     }

     void helper(int start, int n, int k) {
         if (tmp_.size() == k) {
             result_.push_back(tmp_);
             return;
         }
         if (tmp_.size() + n - start + 1 < k)
             return;
         tmp_.push_back(start);
         helper(start + 1, n, k);
         tmp_.pop_back();
         helper(start + 1, n, k);
     }

 private:
     std::vector<int> tmp_;
     std::vector<std::vector<int>> result_;
 };
 */
