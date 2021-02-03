//2020.09.27_#-1_泛式递归模版改写

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
    void recursion(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        TreeNode * temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        recursion(node->left);
        recursion(node->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        recursion(root);
        return root;
    }
};
