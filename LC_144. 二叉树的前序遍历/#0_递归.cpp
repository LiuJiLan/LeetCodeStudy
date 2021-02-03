//2020.09.20_#0_递归
//完全自己书写,与标准递归思路相同

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
    vector<int> list;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return list;
        }
        
        list.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return list;
    }
};
