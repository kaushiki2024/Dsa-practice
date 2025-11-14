// C++ code for the deleting a node from end
// in two traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = NULL;
    }
};

Node* deleteNthNodeFromEnd(Node* head, int n) {
    
    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer n nodes
    for (int i = 0; i < n; i++)
        fast = fast->next;

    // If fast becomes NULL, then head 
    // is the nth node from end.
    if (fast == nullptr)
        return head->next;

    // Move both pointers until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    slow->next = slow->next->next;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = deleteNthNodeFromEnd(head, 4);

    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}