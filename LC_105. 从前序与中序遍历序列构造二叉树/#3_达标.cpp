//2020.11.14_#3_达标

//注意看之前的代码
//美观性之前的代码更好看

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> * p_preorder;
    vector<int> * p_inorder;
    int indexOfPreorder;
    
    TreeNode * recursion(int begin, int end) {
        //包括begin,不包括end
        if (indexOfPreorder == p_preorder->size() || begin >= end) {
            return NULL;
        }
        
        TreeNode * node = new TreeNode(p_preorder->at(indexOfPreorder));
        
        int midOfInorder = -1;
        for (int i = begin; i < end; i++) {
            if (p_inorder->at(i) == p_preorder->at(indexOfPreorder)) {
                midOfInorder = i;
            }
        }
        
        indexOfPreorder++;
        
        node->left = recursion(begin, midOfInorder);
        node->right = recursion(midOfInorder + 1, end);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        p_preorder = & preorder;
        p_inorder = & inorder;
        indexOfPreorder = 0;
        TreeNode * root = recursion(0, (int) inorder.size());
        return root;
    }
};
