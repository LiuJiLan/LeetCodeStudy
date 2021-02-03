//2020.10.08_#-1.5_LC官方思路探索
//将1.4的传递vector变为传递边界
//附上测试的代码
//执行用时：执行用时：68 ms, 在所有 C++ 提交中击败了19.45%的用户
//内存消耗：16.9 MB, 在所有 C++ 提交中击败了75.44%的用户
//
//优化思路：
//如果在构造时使用前序构造,
//那么preorder不需要传递一个部分/两个边界
//因为,preorder就是根的排序顺序,只需要每次往后推一位即可

class Solution {
private:
    vector<int> * preorderPoint;
    vector<int> * inorderPoint;
    
    TreeNode * recursion(int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd) {
        //New preorder/inorder includes the index of begin,
        //doesn't include the index of end
        
        if (preorderBegin == preorderEnd) {  //when new preorder size == 0
            return NULL;
        }
        
         
        TreeNode * root = new TreeNode((*preorderPoint)[preorderBegin]);
        vector<int>::iterator midInInorder = find((*inorderPoint).begin(), (*inorderPoint).end(), (*preorderPoint)[preorderBegin]);
        //此行代码可以进一步优化为
        //vector<int>::iterator midInInorder = find((*inorderPoint).begin() + inorderBegin, (*inorderPoint).begin() + inorderEnd, (*preorderPoint)[preorderBegin]);
        int indexOfMidInother = (int) distance((*inorderPoint).begin(), midInInorder);
        
        if (indexOfMidInother - inorderBegin == 0) {
            root->left = NULL;
        } else {
            root->left = recursion(preorderBegin + 1, preorderBegin + 1 + (indexOfMidInother - inorderBegin), inorderBegin, indexOfMidInother);
        }
        
        if (preorderEnd - indexOfMidInother == 1) {  //错误！！！应该是(inorderEnd - indexOfMidInother == 1)
            root->right = NULL;
        } else {
            root->right = recursion(preorderBegin + 1 + (indexOfMidInother - inorderBegin), preorderEnd, indexOfMidInother + 1, inorderEnd);
        }
        
        return root;
    }
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderPoint = &preorder;
        inorderPoint = &inorder;
        
        TreeNode * tree = recursion(0, (int) preorder.size(), 0, (int) inorder.size());
        
        return tree;
    }
};

/*
 int main(int argc, const char * argv[]) {
     vector<int> pre = vector<int>({3,9,20,15,7});
     vector<int> in = vector<int>({9,3,15,20,7});
     Solution test;
     test.buildTree(pre, in);
     
     return 0;
 }
 */
