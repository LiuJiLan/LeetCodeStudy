//2020.10.17_#1_达标


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int indexOfPerorder;
    int sizeOfPeroder;
    
    TreeNode * recursion(int l_inorder, int r_inorder) {
        if (indexOfPerorder == sizeOfPeroder || l_inorder == r_inorder) {
            return NULL;
        }
        
        int indexOfRoot = 0;
        for (int i = l_inorder; i < r_inorder; i++) {
            if ((*p_inorder)[i] == (*p_preorder)[indexOfPerorder]) {
                indexOfRoot = i;
            }
        }
        
        TreeNode * newRoot = new TreeNode((*p_preorder)[indexOfPerorder]);
        indexOfPerorder++;
        newRoot->left = recursion(l_inorder, indexOfRoot);
        newRoot->right = recursion(indexOfRoot + 1, r_inorder);
        
        return newRoot;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        p_preorder = & preorder;
        p_inorder = & inorder;
        indexOfPerorder = 0;
        sizeOfPeroder = (int) preorder.size();
        
        TreeNode * root = recursion(0, sizeOfPeroder);
        
        return root;
    }
};
