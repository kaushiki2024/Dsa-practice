#include<iostream>
#include<Queue>
using namespace std;
class Node{
    public:
       int data;
       Node* left;
       Node* right;

    Node(int d){
        this->data = d;
        this->left= NULL;
        this->right=NULL;
    }
};
Node* BuildTree(Node* root){
    int data;
    cout<<"enter data:"<<endl;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in the left of "<<data<<endl;
    root->left= BuildTree(root->left);
    cout<<"Enter data for inserting in the right of "<<data <<endl;  
    root->right= BuildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
int main(){
    Node* root = NULL;
    root = BuildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);
}