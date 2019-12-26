# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder==[]:
            return None
        root=preorder[0]
        assert len(preorder)==len(inorder)
        if len(preorder)==1:
            return TreeNode(preorder[0])

        node=TreeNode(root)
        left,right,i=[],[],0
        while i<len(inorder) and inorder[i]!=root:
            left.append(inorder[i])
            i+=1
        i+=1
        right=inorder[i:]
        node.left=self.buildTree(preorder[1:1+len(left)],left)
        node.right=self.buildTree(preorder[1+len(left):],right)
        return node