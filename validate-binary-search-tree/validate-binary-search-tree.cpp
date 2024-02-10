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
    void inorder (TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {

        vector<int> ans;
        set<int> sans;
        inorder(root,ans);
       
        for(auto i: ans) sans.insert(i);

        if(ans.size()!=sans.size()) return false;
        int j=0;
        for(auto i:sans){
            if (i!=ans[j]) return false;
            j++;
        }

        return true;

        // if (root==NULL) return true;
        // if(root->right && root->val>=root->right->val) return false;
        // if(root->left && root->val<=root->left->val) return false;
        // return(isValidBST(root->left) && isValidBST(root->right));
    }
};