//2020.10.08_#-1.3_LC官方思路探索
//第一次通过

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {  //Just for unexpected situation
            return NULL;  //Don't know whether it really in need
        }
        
        int rootValue = preorder[0];
        TreeNode * root = new TreeNode(rootValue);
        vector<int>::iterator midInInorder = find(inorder.begin(), inorder.end(), rootValue);
        int numsLeft = (int) distance(inorder.begin(), midInInorder);
        int numsRight = (int) distance(midInInorder, inorder.end());
        //其实没有必要求numsRight
        /*
         int main(int argc, const char * argv[]) {
             vector<int> test = vector<int>({0,1,2,3,4,5,6});
             vector<int>::iterator mid = find(test.begin(), test.end(), 3);
             cout << distance(test.begin(), mid) << "---" << distance(mid, test.end()) << endl;
             //3---4
             //所以为了输出个数应该
             //cout << distance(test.begin(), mid) << "---" << distance(mid, test.end() - 1) << endl;
             return 0;
         }
         */
        
        if (numsLeft == 0) {  //如果rootValue左边的元素为0
            root->left = NULL;
        } else {
            vector<int> leftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + numsLeft);
            vector<int> leftInorder = vector<int>(inorder.begin(), midInInorder);
            root->left = buildTree(leftPreorder, leftInorder);
        }
        
        if (numsRight == 0) {  //如果rootValue右边的元素为0
            root->right = NULL;
        } else {
            vector<int> rightPreorder = vector<int>(preorder.begin() + 1 + numsLeft, preorder.end());
            vector<int> rightInorder = vector<int>(midInInorder + 1, inorder.end());
            root->right = buildTree(rightPreorder, rightInorder);
        }
        
        return root;
    }
};

