//2020.09.19_#0_递归法

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
private:
    vector<int> list;

public:
    vector<int> preorder(Node* root) {
        if (root == NULL) {
            return list;
        }
        
        list.push_back(root->val);
        
        //遍历children的vector数组
        for (int i = 0; i < (root->children).size(); i++) {
            //示例的Cpp中将递归的函数分离了出来,
            //是因为如果在直接用preorder本函数递归,
            //那下面这个函数就会出现函数有返回值但是无变量接收的情况
            preorder((root->children)[i]);
        }
        
        return list;
    }
};

//递归的BestVotes_Java_and_Cpp
/*
class Solution {
    public List<Integer> list = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if (root == null)
            return list;
        
        list.add(root.val);
        for(Node node: root.children)
            preorder(node);
                
        return list;
    }
}
*/

/*
class Solution {
private:
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root -> val);
        for (Node* child : root -> children) {
            travel(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }
};
*/
