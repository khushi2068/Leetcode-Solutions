class Solution {
public:
    void helper(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < sz; i++) {
                Node* temp = q.front();
                q.pop(); // Correctly remove the element from the queue.

                if (prev) {
                    prev->next = temp; // Assign the previous node's next to the current node.
                }
                prev = temp; // Update prev to be the current node for the next iteration.

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            // At the end of each level, the last node's next will already be NULL by default.
        }
    }

    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};
