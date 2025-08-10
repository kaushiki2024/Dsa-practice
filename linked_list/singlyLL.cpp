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
      //inserting at last positon
        if(temp->next == NULL){
            insertAtTail(tail,d);
            return;
        }
        
        //creating a node for d
        Node* nodetoinsert = new Node(d);
        nodetoinsert-> next = temp->next;
        temp ->next = nodetoinsert;
      
}
int main(){
    Node* node1= new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node* head= node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtposition(tail,head,3,17);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;
    return 0; 
}