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
int getlen(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node* findmiddle(Node* head){
    int length=getlen(head);
    int ans=(length/2);
    int cnt=0;
    Node* temp=head;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
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

}