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
        int val = this->data;
          if(this->next  != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"the deleted value of data be "<<val<<endl;     
     }
};
void insertAtTail(Node* &tail,int d){
    //new node create 
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

Node* Sort(Node* head){
    Node* temp = head;
    int zerocount = 0;
    int onecount =  0;
    int twocount =  0;
    while(temp!= NULL){
        if(temp->data == 0){
            zerocount++;
        }
        else if(temp->data == 1){
            onecount++;
        }
        else if(temp->data ==2){
            twocount++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(zerocount!=0){
            temp->data =0;
            zerocount--;
        }
        else if(onecount!=0){
            temp->data = 1;
            onecount--;
        }
        else if(twocount = 2){
            temp->data =2; 
            twocount--;
        }
        temp=temp->next;
    }
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
int main(){
    int n;
    cout<<"Enter number of nodes you want containing data 0,1,2"<<endl;
    cin>>n;
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
    Node* ans = Sort(head);
    print(head);
}