//2020.09.27_#0_BestVotes
//个人觉得不如我自己的#-1写法

class Solution {
private:
    
    void recursion(vector<string> & container,int left, int right, string str, int SIZE) {
        if (right == SIZE) {
            container.push_back(str);
            return;
        }
        
        if (left < SIZE) {
            recursion(container, left + 1, right, str + "(", SIZE);
        }
        if (right < left) {
            recursion(container, left, right + 1, str + ")", SIZE);
        }
    }
    
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(ans, 0, 0, "", n);
        return ans;
    }
};

/*
 class Solution {
 public:
     vector<string> generateParenthesis(int n) {
         vector<string> res;
         addingpar(res, "", n, 0);
         return res;
     }
     void addingpar(vector<string> &v, string str, int n, int m){
         if(n==0 && m==0) {
             v.push_back(str);
             return;
         }
         if(m > 0){ addingpar(v, str+")", n, m-1); }
         if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
     }
 };
 */
