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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      
       if(postorder.size()==0)return NULL;

        int size = postorder.size();
        int root_val = postorder[size-1];

        TreeNode* root = new TreeNode(root_val);
        int temp;
        
        for(int i = 0 ; i < inorder.size() ; i++){
               if(inorder[i]==root_val) temp = i;
        }

        vector<int> left_postorder = vector<int>(postorder.begin(),postorder.begin()+temp);

        vector<int> left_inorder= vector<int>(inorder.begin(),inorder.begin()+temp);
        
        vector<int> right_postorder = vector<int>( postorder.begin()+temp, postorder.end()-1);

        vector<int> right_inorder = vector<int>(inorder.begin()+temp+1, inorder.end());

         root->left = buildTree(left_inorder,left_postorder);
         root->right = buildTree(right_inorder,right_postorder);
        return root;




        
        
    }
};