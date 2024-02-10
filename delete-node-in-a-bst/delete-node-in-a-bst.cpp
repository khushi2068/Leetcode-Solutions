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
    TreeNode* findrightmost(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode *right=root->right;
        TreeNode *left=findrightmost(root->left);
        left->right=right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val==key) return helper(root);
        TreeNode* temp=root;
        while(root!=NULL){
            if(key<root->val){
            if(root->left && root->left->val==key){
                root->left=helper(root->left);
                break;  
            }
            else root=root->left;
            }

            else{
                if(root->right && key==root->right->val){
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }
        }
        return temp;
    }
};