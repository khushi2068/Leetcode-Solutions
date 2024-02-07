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
public:int ans;
        int l,r=1;
    int topdown(TreeNode* root, int depth){
                if(root==NULL) return 0;
                if(!(root->left) && !(root->right))  ans= max(ans,depth);
                int l=topdown(root->left,depth+1);
                int r=topdown(root->right,depth+1);
                return ans;
    }
    int maxDepth(TreeNode* root) {
        
       int a= topdown(root,1);
        return a;

        
    }
};