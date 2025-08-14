#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void reverse(Node* &head, Node* curr, Node* prev) {
    if (curr == NULL) {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head, forward, curr); 
    curr->next = prev;            
}

Node* reverseLL(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "\nOriginal List: ";
    print(head);

    head = reverseLL(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}
