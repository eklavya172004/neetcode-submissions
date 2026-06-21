/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        if(!root) return "#";

        queue<TreeNode*> pq;

        pq.push(root);

        string ans = "";

        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();

            if(node == nullptr){
                ans += "#,";
                continue;
            }

            ans += to_string(node->val)+",";

            pq.push(node -> left);
            pq.push(node -> right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
TreeNode* deserialize(string data) {

    if(data == "#") return nullptr;

    stringstream ss(data);
    string token;

    getline(ss, token, ',');
    TreeNode* root = new TreeNode(stoi(token));

    queue<TreeNode*> pq;
    pq.push(root);

    while(!pq.empty()) {

        TreeNode* curr = pq.front();
        pq.pop();

        // left child
        if(getline(ss, token, ',')) {
            if(token != "#") {
                curr->left = new TreeNode(stoi(token));
                pq.push(curr->left);
            }
        }

        // right child
        if(getline(ss, token, ',')) {
            if(token != "#") {
                curr->right = new TreeNode(stoi(token));
                pq.push(curr->right);
            }
        }
    }

    return root;
} 
};
