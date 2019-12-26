class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& pre, int pre_from, int pre_to, vector<int>& in, int in_from, int in_to){
        if(pre_to - pre_from < 0 || in_to - in_from < 0)
            return NULL;
        int mid = pre[pre_from];
        int i = in_from;
        for(; i <= in_to; ++i){
            if(in[i] == mid)
                break;
        }
        TreeNode* root = new TreeNode(mid);
        // 下标i左边的数目是i - in_from个。
        root -> left = helper(pre, pre_from + 1, pre_from + i - in_from, in, in_from, i - 1);
        root -> right = helper(pre, pre_from + i - in_from + 1, pre_to, in, i + 1, in_to);
        return root;
    }
};