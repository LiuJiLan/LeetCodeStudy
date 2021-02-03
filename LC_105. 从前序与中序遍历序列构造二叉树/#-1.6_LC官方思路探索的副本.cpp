//2020.10.08_#-1.7_LC官方思路探索

class Solution {
private:
    vector<int> * preorderPoint;
    vector<int> * inorderPoint;
    int indexOfPreorder;
    int sizeOfPreorder;
    
    TreeNode * recursion(int inorderBegin, int inorderEnd) {
        if (indexOfPreorder >= sizeOfPreorder) {  //when new preorder size == 0
            return NULL;
        }
        
        TreeNode * root = new TreeNode((*preorderPoint)[indexOfPreorder]);
        int indexOfMidInother = 0; //for safety
        
        for (int i = inorderBegin; i < inorderEnd; i++) {
            if ((*preorderPoint)[indexOfPreorder] == (*inorderPoint)[i]) {
                indexOfMidInother = i;
                break;
            }
        }
        
        indexOfPreorder++;
        
        if (indexOfMidInother - inorderBegin == 0) {
            root->left = NULL;
        } else {
            root->left = recursion(inorderBegin, indexOfMidInother);
        }
        
        if (inorderEnd - indexOfMidInother == 1) {
            root->right = NULL;
        } else {
            root->right = recursion(indexOfMidInother + 1, inorderEnd);
        }
        
        return root;
    }
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderPoint = &preorder;
        inorderPoint = &inorder;
        indexOfPreorder = 0;
        sizeOfPreorder = (int) preorder.size();
        
        TreeNode * tree = recursion(0, (int) inorder.size());
        
        return tree;
    }
};

//4ms代码
/*
 class Solution {
 public:
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if (!preorder.size()) return nullptr;

         TreeNode* root = new TreeNode(preorder[0]);
         stack<TreeNode*> stk;
         stk.push(root);
         int inorderIndex = 0;
         for (int i = 1; i < preorder.size(); i++) {
             int preorderVal = preorder[i];
             TreeNode* node = stk.top();
             if (node->val != inorder[inorderIndex]) {
                 node->left = new TreeNode(preorderVal);
                 stk.push(node->left);
             }
             else {
                 while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                     node = stk.top();
                     stk.pop();
                     inorderIndex++;
                 }
                 node->right = new TreeNode(preorderVal);
                 stk.push(node->right);
             }
         }
         return root;
     }
 };
 */
