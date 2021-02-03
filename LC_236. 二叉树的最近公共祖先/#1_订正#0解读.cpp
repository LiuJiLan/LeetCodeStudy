//2020.10.06_#1_订正#0解读

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        //订正一个#0解读中的错误
        //这个错误直接与recursion的终止条件挂钩
        //#0的解读中,我认为整个遍历是先DFS到达最底层叶子树
        //但如果要满足这个调节就要将递归终止条件改为if (root == NULL)
        //以避免当 root == p || root == q 时未下探到叶子树就终止
        //但事实上不需要探测到底
        //
        //只有两种情况
        //(1)终止的node是另一个target的祖先节点,那么其他的分支的回馈值都会是NULL,这就是答案
        //(2)终止的node不是是另一个target的祖先节点，
        //说明他们是分配在他们的最近公共祖先节点的两个分支上的(稍微思考即可确认这个想法)
        //那么这当在这两个目标节点终止递归后,会同时向上返回非NULL值,
        //当最近公共祖先节点的process部分接收到两个非NULL值就会返回自己本身,这就是答案
    
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        
        return root;
    }
};
