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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> pq;

        pq.push(root);
        
        bool yes = false;

        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();

            if(node->val == subRoot->val){
                yes = traverse(node,subRoot);
            }

            if(yes) return yes;

            if(node->left){
               pq.push(node->left); 
            }

            if(node->right){
                pq.push(node->right);
            }
        }

        return false;    
    }

    bool traverse(TreeNode* node,TreeNode* sub){
        if(node == nullptr && sub == nullptr) return true;
        if(sub == nullptr || node == nullptr) return false;
        if(node->val != sub->val) return false;

        return traverse(node->left,sub->left) && traverse(node->right,sub->right);
    }
};
