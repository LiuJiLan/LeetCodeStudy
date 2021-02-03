//2020.09.27_#-2_中序遍历法
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
    
    void walk(TreeNode* root) {
        if (root != NULL) {
            walk(root->left);
            list.push_back(root->val);
            walk(root->right);
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        walk(root);
        
        for (int i = 0;i < list.size()-1; i++) {
            if (list[i] > list[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};
