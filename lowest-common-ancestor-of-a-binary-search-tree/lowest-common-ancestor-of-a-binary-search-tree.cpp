class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL or root is either p or q
        if (root == NULL || root == p || root == q) return root;
        
        // Search for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are not NULL, root is the LCA
        if (left != NULL && right != NULL) return root;
        
        // If one of the subtrees contains both p and q, return that subtree
        // If left is not NULL, p and q are found in the left subtree
        // If right is not NULL, p and q are found in the right subtree
        // If both are NULL, it means p and q were not found in either subtree
        return left != NULL ? left : right;
    }
};
