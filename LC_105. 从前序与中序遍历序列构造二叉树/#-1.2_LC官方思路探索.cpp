//2020.10.08_#-1.2_LC官方思路探索
//部分用例正确
//错误的原因：
//划分 子前序遍历 的方法有误
//不能用某个具体的数/迭代器去划分
//可以直接用inorder中midInInorder前后元素的个数来划分

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
        //返回 root->val 值的迭代器,同时也是原 inorder 的分界点
        //放在if条件句外正是因为 midInInorder 前段是左子树,后半是右子树
        vector<int>::iterator midInPreorder = preorder.begin();
        //为什么在 leftPreorder 使用的迭代器在if条件之外声明,而 leftPreorder 在之内声明？
        //因为只有判断 midInInorder 和 inorder.begin() 和 inorder.end() - 1
        //才能判断到底需不需要去生成 left/rightInorder + left/rightPreorder
        //但是如果将迭代器放在if中，就会出现在left判断的if中生成并泯灭一次迭代器，
        //在right判断的if中再次生成并泯灭一次迭代器的重复。
        //
        //为什么在 midInPreorder 的初值是 preorder.begin()？
        //如果left判断的if认定需要生成左子树(左子树不为NULL)
        //那么会在left判断的else中更新 midInPreorder 为正确的值。
        //如果left判断的if认定不需要生成左子树(左子树为NULL)
        //如果在left判断的else中更新 midInPreorder 的值,
        //那么这个值其实是 rightPreorder 的首项的前一个
        //所以！！！注意！！！
        //midInPreorder 的初值是 preorder.begin() 而不是 preorder.begin() + 1 ，
        //这是我第一次写犯下的错误
        //因为既然左子树为NULL,那么从第二位(下标为1)开始都是rightPreorder
        //为了与“left判断的else中更新了 midInPreorder”后的情况
        //vector<int> rightPreorder = vector<int>(midInPreorder + 1, preorder.end());对应
        //才会出现 midInPreorder 这个值其实是 rightPreorder 的首项的前一个
        //
        //为什么出现preorder.begin() + 1 的错误
        //因为当时在考虑时还没真实写出left判断的else中的实际语句
        //导致预想的和实现的有些出入,稍微修改即可
        //错误用例： preorder = [1,2], inorder = [1,2]
        
        if (midInInorder == inorder.begin()) {  //如果rootValue就已经是inorder的首元素
            root->left = NULL;
        } else {
            vector<int> leftInorder = vector<int>(inorder.begin(), midInInorder);
            midInPreorder = find(preorder.begin(), preorder.end(), leftInorder.back());
            vector<int> leftPreorder = vector<int>(preorder.begin() + 1, midInPreorder + 1);
            //leftPreorder为何要在leftInorder之后声明？
            //是因为leftInorder的最后一个元素也是leftPreorder的截止处
            //例题中：preorder = [3,9,20,15,7] inorder = [9,3,15,20,7]
            //那么leftInorder = [9]，leftPreorder = [9]
            //注意！！！这里逻辑是错的,一旦左子树没有右孙树,就没法用这个方法划分
            //但是可以用个数划分，因为 leftInorder 是等于 leftPreorder的
            
            root->left = buildTree(leftPreorder, leftInorder);
        }
        
        if (midInInorder == inorder.end() - 1) {  //如果rootValue就已经是inorder的尾元素
            root->right = NULL;
        } else {
            vector<int> rightInorder = vector<int>(midInInorder + 1, inorder.end());
            vector<int> rightPreorder = vector<int>(midInPreorder + 1, preorder.end());
            
            root->right = buildTree(rightPreorder, rightInorder);
        }
        
        return root;
    }
};
