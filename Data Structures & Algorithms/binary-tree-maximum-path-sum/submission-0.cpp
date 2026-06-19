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
    int maxPathSum(TreeNode* root) {
    
        int path = INT_MIN;
        pathsum(root,path);

        return path;
    }

    int pathsum(TreeNode* root,int& path){
        if(root == nullptr) return 0;

        int left = max(0,pathsum(root->left,path));
        int right = max(0,pathsum(root->right,path));

        path = max(left+right+root->val,path);

        return root->val + max(left,right);
    } 
};
