#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Simple Binary Tree Node 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for Reverse Level Order Traversal
void reverseLevelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Push current node into stack
        s.push(curr);

        // Enqueue right child first, so left is printed first when reversed
        if (curr->right)
            q.push(curr->right);
        if (curr->left)
            q.push(curr->left);
    }

    // Print nodes in reverse level order
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Reverse Level Order Traversal: ";
    reverseLevelOrder(root);

    return 0;
}
