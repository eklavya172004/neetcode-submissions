class Solution {
public:
    int ans = -1;
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {
        kthsmall(root,k);
        return ans;
    }

    void kthsmall(TreeNode* node,int k){
        if(node == nullptr) return;

        kthsmall(node->left,k);
        count++;

        if(count == k){
            ans = node->val;
            return;
        }

        kthsmall(node->right,k);
    }
};
