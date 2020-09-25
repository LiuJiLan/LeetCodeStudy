//2020.09.20_#0_改写自官方Java递归算法

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
    
    void traverseNode(Node* node, int level) {
        if (list.size() <= level) {
            list.push_back(vector<int>());
        }
        
        list[level].push_back(node->val);
        
        for (int i = 0; i < (node->children).size(); i++) {
            traverseNode((node->children)[i], level + 1);
        }
    }

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if (root != NULL) {
            traverseNode(root, 0);
        }
        
        
        return list;
    }
};

/*
class Solution {

    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        if (root != null) traverseNode(root, 0);
        return result;
    }

    private void traverseNode(Node node, int level) {
        if (result.size() <= level) {
            result.add(new ArrayList<>());
        }
        result.get(level).add(node.val);
        for (Node child : node.children) {
            traverseNode(child, level + 1);
        }
    }
}

*/
