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
        //memory free
        if(this->next  != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data : "<<value<<endl;
     }
};
void insertAtHead(Node* &head,int d){
    //new code create
    Node* temp=new Node(d);
    temp->next = head;
    head = temp;

}


void insertAtTail(Node* &tail,int d){
    //new node create 
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}
void insertAtposition(Node* &tail,Node* &head,int position,int d){
    Node* temp = head;
    int cnt=1;
    if(position == 1){
        insertAtHead(head,d);
        return;
    }
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
      //inserting at last position
        if(temp->next == NULL){
            insertAtTail(tail,d);
            return;
        }
        
        //creating a node for d
        Node* nodetoinsert = new Node(d);
        nodetoinsert-> next = temp->next;
        temp ->next = nodetoinsert;
      
}
 void deleteNode(int position,Node* &head,Node* &tail){
     //deleting first node
     if(position==1){
        Node* temp=head;
        head=head->next;
        //memory free node
        temp->next=NULL;
        delete temp;
     }
     else{
        //deleting node at any position leaving first
        Node* curr=head;
        Node* prev=NULL;
      
        int cnt=1;
        while(cnt < position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
    
        prev->next=curr->next;
        if (curr->next == NULL) { //update tail when deleting last node
            tail = prev;
        }
        curr->next=NULL;
        delete curr;
     }
 }

int main() {
    int n;
    cout << "Enter number of nodes you want to create: ";
    cin >> n;

    int value;
    cout << "Enter value for node 1: ";
    cin >> value;

    // Create first node
    Node* node1 = new Node(value);
    Node* head = node1;
    Node* tail = node1;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> value;
        insertAtTail(tail, value);
    }
    //Node* node1= new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    //Node* head= node1;
    //Node* tail=node1;
    //print(head);
    //insertAtTail(tail,12);
    //print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtposition(tail,head,3,17);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;
    deleteNode(4,head,tail);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;

    return 0; 
}