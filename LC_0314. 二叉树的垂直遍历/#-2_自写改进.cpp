//2021.02.11_#-2_自写改进


// 改进思路
// 因为BFS自带一个从左到右, 从上自下的顺序
// 在-1的基础上去掉在外部使用的unordered_map,
// 改用一个外在的queue来储存x的信息

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
    queue<int> xQueue;
    map<int, vector<int>> xVectorTable;
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        
        xVectorTable = map<int, vector<int>>();
        
        queue<TreeNode *> nodeQueue = queue<TreeNode *>();
        
        nodeQueue.push(root);
        xQueue.push(0);
        
        while (!nodeQueue.empty()) {
            int count = (int)nodeQueue.size();
            while (count-- > 0) {
                TreeNode * node = nodeQueue.front();
                nodeQueue.pop();
                
                int x = xQueue.front();
                xQueue.pop();
                
                if (xVectorTable.count(x) == 0) {
                    xVectorTable[x] = vector<int>();
                }
                xVectorTable[x].push_back(node->val);
                
                if (node->left != NULL) {
                    nodeQueue.push(node->left);
                    xQueue.push(x - 1);
                }
                if (node->right != NULL) {
                    nodeQueue.push(node->right);
                    xQueue.push(x + 1);
                }
            }
        }
        
        vector<vector<int>> ans = vector<vector<int>>();
        for (auto item : xVectorTable) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};

#if 0

class Solution {

private:
    map<int,int> hasht;
    vector<vector<int>> ans;


public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        queue<int> state;
        q.push(root);
        state.push(0);

        while(q.size()!=0){
            auto temp = q.front();
            auto temp_state = state.front();
            q.pop();
            state.pop();

            if(hasht.find(temp_state) == hasht.end()){
                vector<int> ans_layer;
                ans_layer.push_back(temp->val);
                ans.push_back(ans_layer);
                hasht[temp_state] = ans.size()-1;
            }
            else{
                ans[hasht[temp_state]].push_back(temp->val);
            }
            if(temp->left != NULL){
                q.push(temp->left);
                state.push(temp_state - 1);
            }
            if(temp->right != NULL){
                q.push(temp->right);
                state.push(temp_state + 1);
            }

        }

        vector<vector<int>> ordered_ans;
        for(auto &it:hasht){
            ordered_ans.push_back(ans[(it).second]);
        }
        return ordered_ans;
    }
};


#endif
