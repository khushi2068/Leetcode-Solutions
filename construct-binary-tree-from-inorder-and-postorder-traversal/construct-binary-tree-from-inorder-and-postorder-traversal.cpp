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
    
    TreeNode* helper(vector<int>& inorder,int is, int ie, vector<int>& postorder, int ps, int pe) {
        if((is>ie) ||( ps>pe)) return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int idx=find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
        
        root->left=helper(inorder,is,idx-1,postorder,ps,ps+idx-is-1);
        root->right=helper(inorder,idx+1,ie,postorder,ps+idx-is,pe-1);
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.empty()) return NULL;
        int is=0;
        int ie=inorder.size()-1;
        int ps=0;
        int pe=postorder.size()-1;
        return helper(inorder,is,ie,postorder,ps,pe);
        
    }
};