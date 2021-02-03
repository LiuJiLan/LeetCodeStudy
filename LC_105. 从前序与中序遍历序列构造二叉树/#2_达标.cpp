//2020.10.31_#2_达标


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
    vector<int> * preorderPoint;
    vector<int> * inorderPoint;
    int indexOfPerorder;
    
    TreeNode* buildTreeAssist( int inorderBegin, int inorderEnd) {
        if (indexOfPerorder >= preorderPoint->size()) {
            return NULL;
        }
        
        TreeNode * node = new TreeNode(preorderPoint->at(indexOfPerorder));
        
        int indexOfMidOfInorder = 0;
        for (int i = inorderBegin; i < inorderEnd; i++) {
            if(inorderPoint->at(i) == preorderPoint->at(indexOfPerorder)) {
                indexOfMidOfInorder = i;
                break;
            }
        }
        
        indexOfPerorder++;
        //不能node->leftOrRight = buildTreeAssist(indexOfPerorder++, inorderBegin, indexOfMidOfInorder);
        //也不能让局部变量indexOfPerorder++,indexOfPerorder应该是公用元素
        
        if (inorderBegin < indexOfMidOfInorder) {
            node->left = buildTreeAssist(inorderBegin, indexOfMidOfInorder);
        }
        if (indexOfMidOfInorder < inorderEnd - 1) {
            node->right = buildTreeAssist(indexOfMidOfInorder + 1, inorderEnd);
        }
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderPoint = & preorder;
        inorderPoint = & inorder;
        indexOfPerorder = 0;
        
        TreeNode * root = buildTreeAssist(0, (int) inorder.size());
        
        return root;
    }
};
