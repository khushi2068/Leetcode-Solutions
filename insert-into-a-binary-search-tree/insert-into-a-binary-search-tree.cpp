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
    TreeNode* helper(TreeNode *root,TreeNode* newnode){
        if(root==NULL) return newnode;
        if(newnode->val>root->val) root->right=helper(root->right,newnode);
        if(newnode->val<root->val) root->left=helper(root->left,newnode);
        return root;
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        return helper(root,newnode);
    }
};