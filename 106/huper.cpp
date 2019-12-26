class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int> in, int in_from, int in_to, vector<int> post, int post_from, int post_to){
        if(in_to - in_from < 0 || post_to - post_from < 0)
            return NULL;
        int mid = post[post_to];
        int i = in_from;
        for(;i <= in_to; ++i){
            if(in[i] == mid)
                break;
        }
        TreeNode* root = new TreeNode(mid);
        root -> left = helper(in, in_from, i - 1, post, post_from, post_from + i - in_from - 1);
        root -> right = helper(in, i + 1, in_to, post, post_from + i - in_from, post_to - 1);
        return root;
    }
};