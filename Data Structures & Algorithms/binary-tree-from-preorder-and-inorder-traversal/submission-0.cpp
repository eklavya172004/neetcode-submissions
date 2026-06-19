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
    unordered_map<int,int> mp;
    int index = 0 ;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // take the ith node from the preorder 
        // find it in the indorder make the root node and pass
        //  the rest left and right elements of the inorder  
        for(int i = 0; i < inorder.size() ; i++){
            mp[inorder[i]]=i;
        }

        return helper(preorder,0,inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder,int left,int right){
        if(left>right) return nullptr;

        int root = preorder[index++];
        
        TreeNode* node = new TreeNode(root);
        int mid = mp[root];

        node -> left = helper(preorder,left,mid-1);
        node -> right = helper(preorder,mid+1,right);

        return node;
    }
};
