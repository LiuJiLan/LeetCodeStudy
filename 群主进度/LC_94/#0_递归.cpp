//2020.09.20_#0_递归
//完全自己书写,与标答递归思路相同

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
vector<int> list;
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return list;
        }
        
        //注意:
        //标答新建了一个函数来进行递归
        //避免有返回值的inorderTraversal无值接收
        inorderTraversal(root->left);
        list.push_back(root->val);
        inorderTraversal(root->right);
        
        return list;
    }
};

//LeetCode_官方标答
/*

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

*/
