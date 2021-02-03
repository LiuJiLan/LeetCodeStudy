//2020.10.08_#-1.1_LC官方思路探索
//未完成

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode * inConstruct(int rootVal, vector<int> leftSubTree, vector<int> rightSubTree) {
        TreeNode * root = new TreeNode(rootVal);  //set the root value
        
        vector<int> rootLeftSubTree = vector<int>();  //Initialize the leftSubTree array of the root
        vector<int> rootRightSubTree = vector<int>();  //Initialize the rightSubTree array of the root
        
        if (leftSubTree.size() == 0) {
            root->left = NULL;
        } else {
            // a function to seperate the leftSubTree to new leftSubTree and new rightSubTree
            // So, it's definitely can make a recursion directly use preorder array and inorder array
        }
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * newTree = new TreeNode(0);  //just to silense the warning/error.
        //Now, I already have a idea to deal with this problem.
        return newTree;  //just to silense the warning/error.
    }
};
