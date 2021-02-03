//2020.09.27_#0_BestVotes+解读
//示例代码为代码艺术可读性较差

/**Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        return root;
    }
};

//解释：
//本质上数据是从下往上(从深往浅)上升
//将p、q节点称为目标节点,将p、q节点的最近公共祖节点称为答案节点。
//几个特殊点的返回值

//1.对于一个节点的左右子节点中同时皆为NULL,那么这个节点将返回NULL。
//将会有以下三个重点情况：
//1_1.对于触底的叶节点,对于叶节点的left和right都为NULL,所以返回的是叶节点本身。
//1_2.如果叶节点本身是目标节点,那么叶节点将返回非NULL值(本质上是目标节点的指针)。
//1_3.对于一个节点的(全部)根节点中没有目标节点,那么这个节点将返回NULL

//2.对于一个节点的左右子节点中同时皆为非NULL,将向上返回非NULL的值(本质上是此节点自己的指针)。
//其实这个节点就是答案节点,为了方便后面解释我们也称这个节点为临界节点。

//3.对于一个节点,它的一个子返回非NULL值,另一个子返回NULL值。将会有以下两种情况。
//3_1.当深于临界节点,这个节点将向上返回非NULL的值,这个非NULL值就是其中一个目标节点的指针。
//3_2.当浅于临界节点,这个节点将向上返回非NULL的值,这个非NULL值就是答案节点的指针。




//4Lines_Cpp_Recursion
/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
*/
