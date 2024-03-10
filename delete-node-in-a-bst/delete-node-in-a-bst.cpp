class Solution {
public:
    TreeNode* findRightmost(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val == key) {
            // Node with only one child or no child
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            }
            // Node with two children: Get the inorder predecessor (rightmost in left subtree)
            TreeNode* inOrderPredecessor = findRightmost(root->left);
            // Copy the inOrderPredecessor's content to root
            root->val = inOrderPredecessor->val;
            // Delete the inOrderPredecessor
            root->left = deleteNode(root->left, inOrderPredecessor->val);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
