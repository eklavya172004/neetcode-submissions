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
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }

    bool valid(TreeNode* node,long long minVal,long long maxVal){
        if(node == nullptr) return true;

        if(node->val <= minVal || node->val >= maxVal){
            return false;
        }

        return valid(node->left,minVal,node->val) 
        && 
        valid(node->right,node->val,maxVal);
    }
};
