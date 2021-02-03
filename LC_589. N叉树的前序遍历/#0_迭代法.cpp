//2020.09.19_#0_迭代法
//注意Cpp中要筛查Node* 是否为NULL

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    };
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> list;
        
        if (root == NULL) {
            return list;
        }
        
        //Using stack is actually a dummy Recursive solution
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            //val root is just to save a space of a new value
            root = stk.top();
            stk.pop();
            list.push_back(root->val);
            
            //遍历children的vector数组
            //Nitice:前序法,但stack先进后出,所以从后往前压栈
            
            //if的原因:
            //在Java中如果(root->children)[index] == NULL,
            //在读取(root->children)[index]->val时并不会出错,
            //但Cpp会
            for (int i = (root->children).size()-1; i >= 0; i--) {
                if ((root->children)[i] != NULL) {
                    stk.push((root->children)[i]);
                }
            }
        }
        
        return list;
    }
};

//迭代的BestVotes_Java_and_Cpp
/*
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;
        
        Stack<Node> stack = new Stack<>();
        stack.add(root);
        
        while (!stack.empty()) {
            root = stack.pop();
            list.add(root.val);
            for (int i = root.children.size() - 1; i >= 0; i--)
                stack.add(root.children.get(i));
        }
        
        return list;
    }
}
*/

/*
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            result.push_back(cur -> val);
            for (int i = cur -> children.size() - 1; i >= 0; i--) {
                if (cur -> children[i] != nullptr) {
                    stk.push(cur -> children[i]);
                }
            }
        }
        return result;
    }
};
*/
