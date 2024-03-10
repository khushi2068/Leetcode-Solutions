class Solution {
public:
    TreeNode* findrightmost(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    
    TreeNode* helper(TreeNode* root){
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        
        TreeNode *left = root->left;
        TreeNode *rightmost = findrightmost(left);
        rightmost->right = root->right;
        return left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val == key) return helper(root);
        if (root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};
