//2020.10.08_#-1.4_LC官方思路探索
//仅在#-1.3基础上做了小的改动
//附上测试的代码
//执行用时：72 ms, 在所有 C++ 提交中击败了17.60%的用户
//内存消耗：64.7 MB, 在所有 C++ 提交中击败了12.30%的用户
//高用时和高内存来自对vector的反复复制
//可以通过引用+传递前后界来进行加速

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
        //int numsRight = (int) distance(midInInorder, inorder.end());
        //其实没有必要求numsRight
        //vector<int> rightPreorder = vector<int>(preorder.begin() + 1 + numsLeft, preorder.end());即可
        
        if (numsLeft == 0) {  //如果rootValue左边的元素为0
            root->left = NULL;
        } else {
            vector<int> leftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + numsLeft);
            vector<int> leftInorder = vector<int>(inorder.begin(), midInInorder);
            root->left = buildTree(leftPreorder, leftInorder);
        }
        
        if (midInInorder == inorder.end() - 1) {
            root->right = NULL;
        } else {
            vector<int> rightPreorder = vector<int>(preorder.begin() + 1 + numsLeft, preorder.end());
            vector<int> rightInorder = vector<int>(midInInorder + 1, inorder.end());
            root->right = buildTree(rightPreorder, rightInorder);
        }
        
        return root;
    }
};

/*
 #include <iostream>
 #include <vector>
 #include <string>
 #include <stack>
 #include <queue>
 #include <map>
 #include <unordered_map>
 #include <algorithm>

 using namespace std;

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

//人脑的思路
/*
recursion (preorder, inorder){
    preorder的第一个就是这个node的value;
    哪半边没有直接给赋NULL;
    inorder中value左边的部分就是 子recursion 的inorder参数;
    inorder中value左边同时在preorder中的部分就是 子recursion 的preorder参数;
    recursion();
}
*/
