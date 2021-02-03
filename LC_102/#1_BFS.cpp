//2020.09.27_#1_BFS

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
        vector<vector<int>> list = vector<vector<int>>();
        if (root == NULL) {
            return list;
        }
        
        queue<TreeNode*> nodeQueue = queue<TreeNode*>();
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            vector<int> subList = vector<int>();
            
            for (int i = 0, nowSize = (int)nodeQueue.size(); i < nowSize; i++) {
                TreeNode * nowNode = nodeQueue.front();
                nodeQueue.pop();
                
                subList.push_back(nowNode->val);
                
                if (nowNode->left != NULL) {
                    nodeQueue.push(nowNode->left);
                }
                if (nowNode->right != NULL) {
                    nodeQueue.push(nowNode->right);
                }
            }
            
            list.push_back(subList);
        }
        
        return list;
    }
};
