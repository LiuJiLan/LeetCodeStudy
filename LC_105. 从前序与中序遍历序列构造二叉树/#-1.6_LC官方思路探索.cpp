//2020.10.08_#-1.6_LC官方思路探索
//
//优化思路：
//放弃迭代器的方式查找

class Solution {
private:
    vector<int> * preorderPoint;
    vector<int> * inorderPoint;
    int indexOfPreorder;
    int sizeOfPreorder;
    
    TreeNode * recursion(int inorderBegin, int inorderEnd) {
        if (indexOfPreorder >= sizeOfPreorder) {  //when new preorder size == 0
            return NULL;
        }
        
        TreeNode * root = new TreeNode((*preorderPoint)[indexOfPreorder]);
        vector<int>::iterator midInInorder = find((*inorderPoint).begin() + inorderBegin, (*inorderPoint).begin() + inorderEnd, (*preorderPoint)[indexOfPreorder]);
        int indexOfMidInother = (int) distance((*inorderPoint).begin(), midInInorder);
        
        indexOfPreorder++;
        
        if (indexOfMidInother - inorderBegin == 0) {
            root->left = NULL;
        } else {
            root->left = recursion(inorderBegin, indexOfMidInother);
        }
        
        if (inorderEnd - indexOfMidInother == 1) {
            root->right = NULL;
        } else {
            root->right = recursion(indexOfMidInother + 1, inorderEnd);
        }
        
        return root;
    }
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderPoint = &preorder;
        inorderPoint = &inorder;
        indexOfPreorder = 0;
        sizeOfPreorder = (int) preorder.size();
        
        TreeNode * tree = recursion(0, (int) inorder.size());
        
        return tree;
    }
};
