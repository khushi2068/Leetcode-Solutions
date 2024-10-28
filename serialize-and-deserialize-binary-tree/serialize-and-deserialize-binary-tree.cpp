#include <string>
#include <queue>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "null";
        string s;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr) {
                s += to_string(curr->val) + ","; // Add a comma as delimiter
                q.push(curr->left);
                q.push(curr->right);
            } else {
                s += "null,"; // Add "null" for missing nodes
            }
        }
        
        // Remove the trailing comma
        if (!s.empty()) s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Deserialize left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->left = new TreeNode(stoi(item));
                    q.push(curr->left);
                }
            }
            
            // Deserialize right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->right = new TreeNode(stoi(item));
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};

// Usage
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
