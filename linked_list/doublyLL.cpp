#include<iostream>
using namespace  std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    //constructor 
    Node(int d ){
        this->data=d;
        this->prev = NULL;
        this->next = NULL;
    } 
    //Destructor
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }    
};
void print(Node* head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp!= NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertATHead(Node* &tail,Node* &head, int d){
    if(head==NULL){
        //empty list
        Node* temp= new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head  = temp;
}
void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
        return;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtposition(Node* &tail,Node* &head,int position,int d){
    Node* temp = head;
    if(position == 1){
        insertATHead(tail,head,d);
        return;
    }
    int cnt=1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    //inserting at last position
    if(temp->next == NULL){
        insertAtTail(tail,head,d);
        return;
    }
    
    Node* nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
    
        
}
 void deleteNode(int position,Node* &head,Node* &tail){
     //deleting first node
     if(position==1){
        Node* temp=head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        //memory free node
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
       
        curr->prev = NULL;
        prev->next = curr->next;
       
        if (curr->next == NULL) { //update tail when deleting last node
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
     }
 }
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    //cout<<getLength(head)<<endl;
   

    insertATHead(tail,head,11);
    print(head);
    insertAtTail(tail,head,16);
    print(head);
    insertAtposition(tail,head,3,12);
    print(head);
    insertAtposition(tail,head,4,14);
    print(head);
    deleteNode(5,head,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    return 0;
}