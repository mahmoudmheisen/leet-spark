/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        return dfs(node, cloneMap);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        if (cloneMap.count(node))
            return cloneMap[node];

        Node* cloned = new Node(node->val);
        cloneMap[node] = cloned;

        for (Node* neighbor : node->neighbors) {
            Node* clonedNeighbor = dfs(neighbor, cloneMap);
            cloned->neighbors.push_back(clonedNeighbor);
        }

        return cloned;
    }
};