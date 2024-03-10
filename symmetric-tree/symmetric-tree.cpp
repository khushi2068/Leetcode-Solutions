/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEqual(TreeNode *left,TreeNode *right){
        if(left==NULL ||right==NULL) return left==right;
        if(left->val!=right->val) return false;
        return checkEqual(left->left,right->right) && checkEqual(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL || root->right==NULL) return root->left==root->right;
        return checkEqual(root->left,root->right);
    }
};