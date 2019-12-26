/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);

        
        int temp;
        for(int i = 0 ; i < inorder.size() ; i++){
               if(inorder[i]==root_val) temp = i;
        }
        vector<int> left_preorder = vector<int>(preorder.begin()+1,preorder.begin()+temp+1);
        vector<int> left_inorder= vector<int>(inorder.begin(),inorder.begin()+temp);
        
        vector<int> right_preorder = vector<int>(preorder.begin()+temp+1,preorder.end());
        vector<int> right_inorder = vector<int>(inorder.begin()+temp+1, inorder.end());

         root->left = buildTree(left_preorder,left_inorder);
         root->right = buildTree(right_preorder,right_inorder);
        return root;








        
    }
};