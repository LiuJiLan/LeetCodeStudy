//2020.09.20_#1_递归达标

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
    }
};
*/

class Solution {
private:
    vector<vector<int>> list;

    void handle(Node* node, int level) {
        if (list.size() <= level) {
            list.push_back(vector<int>());
        }

        list[level].push_back(node->val);

        for (int i = 0; i < (node->children).size(); i++) {
            handle((node->children)[i], level+1);
        }
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root != NULL) {
            handle(root, 0);
        }

        return list;
    }
};
