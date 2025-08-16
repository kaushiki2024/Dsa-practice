#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
};
Node* findmiddle(Node* head){    
    //check LL for empty and single node
    if( head ==NULL||head->next==NULL){
        return head;
    }
    //2 node
    else if(head->next->next==NULL){
        return head->next;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int n;
    cout <<"enter the number of nodes you want in LL: "<<endl;
    cin>>n;
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
    Node* middle=findmiddle(head);
    print(middle);
    return 0;
}