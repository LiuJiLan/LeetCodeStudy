//2020.11.02_#2_递归

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> list;
    
    void DFS(TreeNode * node) {
        if (node == NULL) {
            return;
        }
        DFS(node->left);
        DFS(node->right);
        list.push_back(node->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        list = vector<int>();
        DFS(root);
        return list;
    }
};
