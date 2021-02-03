//2020.09.27_#0_改写自BFS模版


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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> allResults = vector<vector<int>>();
        
        if (root == NULL) {
            return allResults;
        }
        
        queue<TreeNode*> nodes = queue<TreeNode*>();
        
        nodes.push(root);
        
        while (!nodes.empty()) {
            int size = (int)nodes.size();
            vector<int> results = vector<int>();
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                results.push_back(node->val);
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }
            allResults.push_back(results);
        }
        return allResults;
    }
};
