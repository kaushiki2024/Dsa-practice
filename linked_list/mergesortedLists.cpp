#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data : " << value << endl;
    }
};

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeRec(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    if(a->data < b->data){
        a->next = mergeRec(a->next, b);
        return a;
    } else {
        b->next = mergeRec(a, b->next);
        return b;
    }
}

int main() {
    Node* head1 = new Node(1);
    Node* tail1 = head1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);

    Node* head2 = new Node(1);
    Node* tail2 = head2;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);

    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);

    Node* mergedHead = mergeRec(head1, head2);

    cout << "Merged List: ";
    print(mergedHead);

    return 0;
}
