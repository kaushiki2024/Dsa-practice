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
    cout << "Deleted node with value: " << data << endl;
}

};

void insertAtTail(Node* &tail,int d){
    //new node create 
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAttail(Node* &tail, Node* curr){
    tail->next= curr;
    tail = curr;
}


Node* Sort(Node* head){
    //Node creation
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;
    Node* curr = head;
    //creation of separate list 0's,1's,2's
    while(curr!= NULL){
        int val = curr->data;
        if(val == 0){
            insertAttail(zerotail,curr);
        }
        else if(val == 1){
            insertAttail(onetail,curr);
        }
        else if(val == 2){
            insertAttail(twotail,curr);
        }
        curr=curr->next;
    } 
    
    //Merge 3 sublist
    if(onehead->next!=NULL){//1's list not empty
        zerotail->next = onehead->next;
    }
    else{//1's list is empty
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = NULL;
   
    //setup head
    head = zerohead->next;
   // delete dummy nodes
   delete zerohead;
   delete onehead;
   delete twohead; 
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
    
    Node* Ans= Sort(head);
    print(Ans);
}
    