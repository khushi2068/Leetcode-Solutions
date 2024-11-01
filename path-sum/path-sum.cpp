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
    int csum=0;
    bool hasPathSum(TreeNode* root, int targetsum) {
        
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL ) return root->val==targetsum;    
        return (hasPathSum(root->left,targetsum-root->val)||hasPathSum(root->right,targetsum-root->val));
    }
};