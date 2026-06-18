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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> pq;

        int level = 0;

        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        pq.push({root,level});

        while(!pq.empty()){
            TreeNode* node = pq.front().first;
            int l = pq.front().second;
            pq.pop();

            if (l == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[l] = node->val;
            }

            if(node && node->left){
                pq.push({node->left,l+1});
            }

            if(node && node->right){
                pq.push({node->right,l+1});
            }
        }
    
        return ans;
    }
};
