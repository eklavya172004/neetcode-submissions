class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;

        kthSmall(root,k,vec);

        int val = -1;

        for(int i = 0 ; i < vec.size() ; i++){
            if(k-1 == i){
                val = vec[i];
            }
        }
    
        return val;
    }

    void kthSmall(TreeNode* node,int k,vector<int>& vec){
        if(node == nullptr) return;

        kthSmall(node->left,k,vec);
        vec.push_back(node->val);
        kthSmall(node->right,k,vec);
    }
};
