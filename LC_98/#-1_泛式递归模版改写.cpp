//2020.09.27_#-1_泛式递归模版改写

class Solution {
private:
    vector<string> list;
    int SIZE;
    
    void recursion(int left, int right, string str) {
        if (right == SIZE) {
            list.push_back(str);
            return;
        }
        
        if (left < SIZE) {
            recursion(left + 1, right, str + "(");
        }
        if (right < left) {
            recursion(left, right + 1, str + ")");
        }
    }
    
    
public:
    vector<string> generateParenthesis(int n) {
        SIZE = n;
        recursion(0, 0, "");
        return list;
    }
};
