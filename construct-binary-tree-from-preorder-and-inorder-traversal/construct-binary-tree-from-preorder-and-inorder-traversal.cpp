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
    TreeNode* helper(vector<int>& preorder,int ps,int pe, vector<int>& inorder, int is, int ie){
        if(is>ie || ps>pe)return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int idx=find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
        root->left=helper(preorder,ps+1,ps+idx-is,inorder,is,idx-1);
        root->right=helper(preorder,ps+idx-is+1,pe,inorder,idx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || preorder.size()!=inorder.size()) return NULL;
        int is=0;
        int ps=0;
        int ie=inorder.size()-1;
        int pe=preorder.size()-1;
        return helper(preorder,ps,pe,inorder,is,ie);
    }
};