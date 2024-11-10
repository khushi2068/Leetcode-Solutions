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
   int finddepth(TreeNode* root){
        if(root==NULL) return 0;
        int l=finddepth(root->left);
        int r=finddepth(root->right);
        if(abs(l-r)>1||l==-1||r==-1) return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
       return finddepth(root)!=-1;

    }
};