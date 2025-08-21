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
};
Node* KReverse(Node*head,int K){
    //base case
    if(head==NULL){
        return head;
    }
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<K){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    //recursion
    if(next!=NULL){
        head->next=KReverse(next,K);
    }
    //return head of the reversed list
    return prev;
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
    //Node* ans=KReverse(head,2);
    //print(ans);
    Node* ans=KReverse(head,3);
    print(ans);
}
