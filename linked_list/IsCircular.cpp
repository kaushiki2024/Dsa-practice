#include<iostream>
using namespace std;
class Node{
     public:
     int data;
     Node* next;
     //constructor
     Node(int data){
        this->data=data;
        this->next=NULL;
     }
     //destructor
     ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;        }
     cout<<"memory is free for node with data :  "<<this->data<<endl;
     }
};
void insertNode(Node* &tail,int element,int d){
    //assuming that element is present in the list
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //assuming that element is present in the list
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr ->next;        
        }
        //element found->curr is representing element wala node
        Node* temp= new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
void deleteNode(Node* &tail,int value){
    //empty list
    if(tail == NULL){
        cout<<"List is empty,please check again"<<endl;
        return;
    }
    else{
        //non-empty
        //assuming that "value" is present in the LinkedList
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //1 Node LL
        if(curr == prev){
            tail=NULL;
        }
        //>=2 Node LL
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
bool isCircularList(Node* head){
    if(head==NULL){
        return true;
    }
    Node* temp=head->next;
    while(temp!=NULL&&temp!=head){
        temp=temp->next;

    }
    if(temp==head){
        return true;
    }
    return false;
    
}

int main(){
    Node* tail = NULL;
    int data, element;

    cout << "Enter first node data: ";
    cin >> data;
    insertNode(tail, 0, data); // first node

    while (true) {
        cout << "Enter element after which to insert (-1 to stop): ";
        cin >> element;
        if (element == -1) break;
        cout << "Enter new node data: ";
        cin >> data;
        insertNode(tail, element, data);
        print(tail);
    }
    if(isCircularList(tail)){
        cout<<"Linked list is circular"<<endl;
    }
    else{
        cout<<"Linked List is not circular"<<endl;
    }
    //deleteNode(tail,2);
    //print(tail);
    return 0;

}