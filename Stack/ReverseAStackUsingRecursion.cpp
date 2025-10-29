#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&s,int num){
      //base case
      if(s.empty()){
        s.push(num);
        return;
      }
       int x=s.top();
       s.pop();
       insertAtBottom(s,num);
       s.push(x);
}
void reverseStack(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,num);
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

   
    reverseStack(st);

    cout << "Stack from top to bottom: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}