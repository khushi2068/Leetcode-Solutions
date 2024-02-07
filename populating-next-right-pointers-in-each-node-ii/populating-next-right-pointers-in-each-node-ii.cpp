/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node *root){
        if(root==NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            Node *last=nullptr;
            for(int i=sz-1;i>=0;i--){
                Node *temp=q.front();
                q.pop();
                temp->next=last;
                last=temp;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);

            }
            // prev->next=NULL;
        }

    }
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};