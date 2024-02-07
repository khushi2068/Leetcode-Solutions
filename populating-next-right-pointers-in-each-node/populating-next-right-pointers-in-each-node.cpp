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
    void c(Node* l, Node* r){
        if (l==NULL) return;
        r->next=NULL;
        l->next=r;
        c(l->left,l->right);
        c(l->right,r->left);
        c(r->left,r->right);
    }
    Node* connect(Node* root) {
        if(root==NULL) return root;
        c(root->left,root->right);
        return root;
    }
};