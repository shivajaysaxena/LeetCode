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
    Node* connect(Node* root) {
        vector<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            vector<Node*> curr;
            for (auto x : q) {
                if (x && x->left)
                    curr.push_back(x->left);
                if (x && x->right)
                    curr.push_back(x->right);
            }

            for (int i = 0; i < q.size() - 1; i++) {
                q[i]->next = q[i + 1];
            }
            swap(q, curr);
        }
        return root;
    }
};