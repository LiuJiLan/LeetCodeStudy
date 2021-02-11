//2021.02.11_#-1_自写

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
    unordered_map<TreeNode*, int> nodeXTable;
    map<int, vector<int>> xVectorTable;
    // 这里要用map, 因为题目要求是排序的情况
    
    void DFSsetX(TreeNode * node, int x) {
        if (node == NULL) {
            return;
        }
        
        nodeXTable[node] = x;
        DFSsetX(node->left, x - 1);
        DFSsetX(node->right, x + 1);
    }
    
    void BFSsetVector(TreeNode * root) {
        if (root == NULL) {
            return;
        }
        
        queue<TreeNode *> que = queue<TreeNode *>();
        que.push(root);
        
        while (!que.empty()) {
            int count = (int)que.size();
            while (count-- > 0) {
                TreeNode * node = que.front();
                que.pop();
                
                int x = nodeXTable.at(node);
                if (xVectorTable.count(x) == 0) {
                    xVectorTable[x] = vector<int>();
                }
                xVectorTable[x].push_back(node->val);
                
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
        
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        
        // initialize varible
        nodeXTable = unordered_map<TreeNode*, int>();
        xVectorTable = map<int, vector<int>>();
        
        DFSsetX(root, 0);
        BFSsetVector(root);
        
        for (auto item : xVectorTable) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};


// 思路
// 其实很简单,就是设初始横坐标 x = 0
// 每左子树就-1, 右子树就+1
// 但这样虽然能保证垂直的内容但不能保证垂直的循序
// 所以再使用一个纵坐标初始 y = 0, 每深一层就+1
// 但这仍然不能解决左右的问题
// 所以,想法是遍历树两遍,第一遍是单纯得出xy
// 第二遍是使用先遍历左的便利法在往一个hash表中拉链加入


# if 0
class Solution {
private:
    unordered_map<TreeNode*, pair<int, int>> nodeXYTable;
    // 其实不需要y轴
    // 第二遍遍历采用BFS就可以控制从上至下,
    // 从左到右的顺序
    
    void DFSsetXY(TreeNode * node, int x, int y) {
        if (node == NULL) {
            return;
        }
        
        nodeXYTable[node] = pair<int, int>(x, y);
        DFSsetXY(node->left, x - 1, y + 1);
        DFSsetXY(node->right, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        
        // initialize varible
        nodeXYTable = unordered_map<TreeNode*, pair<int, int>>();
        
        DFSsetXY(root, 0, 0);
        
        return ans;
    }
};

#endif

#if 0
class Solution {
private:
    unordered_map<TreeNode*, int> nodeXTable;
    unordered_map<int, vector<int>> xVectorTable;
    
    void DFSsetX(TreeNode * node, int x) {
        if (node == NULL) {
            return;
        }
        
        nodeXTable[node] = x;
        DFSsetX(node->left, x - 1);
        DFSsetX(node->right, x + 1);
    }
    
    void BFSsetVector(TreeNode * root) {
        if (root == NULL) {
            return;
        }
        
        queue<TreeNode *> que = queue<TreeNode *>();
        que.push(root);
        
        while (!que.empty()) {
            int count = (int)que.size();
            while (count-- > 0) {
                TreeNode * node = que.front();
                que.pop();
                
                int x = nodeXTable.at(node);
                if (xVectorTable.count(x) == 0) {
                    xVectorTable[x] = vector<int>();
                }
                xVectorTable[x].push_back(node->val);
                
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
        
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        
        // initialize varible
        nodeXTable = unordered_map<TreeNode*, int>();
        
        DFSsetX(root, 0);
        BFSsetVector(root);
        
        for (auto item : xVectorTable) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};

#endif
