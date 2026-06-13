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
    unordered_map<Node*,Node*> mp;

    void dfs(Node* clone_node,Node* node){

        for(Node* neigh : node -> neighbors){
            if(mp.find(neigh) == mp.end()){
                Node* clone = new Node(neigh->val);
                mp[neigh] = clone;

                clone_node->neighbors.push_back(clone);

                dfs(clone,neigh);
            }else{
                clone_node->neighbors.push_back(mp[neigh]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        dfs(clone_node,node);

        return clone_node;
    }
};
