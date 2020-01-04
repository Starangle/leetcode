class Solution {
private:
    TreeNode* pre = NULL;
    TreeNode* first = NULL, *second = NULL;
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        helper(root);
        if(first && second) swap(first -> val, second -> val); 
    }
    void helper(TreeNode* root) {
        if(root == NULL) return;
        helper(root -> left);
        if(pre != NULL && pre -> val > root -> val) {
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        helper(root -> right);
    }
};