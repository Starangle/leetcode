# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if inorder==[]:
            return None

        assert len(postorder)==len(inorder)
        if len(postorder)==1:
            return TreeNode(postorder[0])
        root=postorder[-1]
        node=TreeNode(root)
        left,right,i=[],[],0
        while i<len(inorder) and inorder[i]!=root:
            left.append(inorder[i])
            i+=1
        i+=1
        right=inorder[i:]
        node.left=self.buildTree(left,postorder[:len(left)])
        node.right=self.buildTree(right,postorder[len(left):-1])
        return node