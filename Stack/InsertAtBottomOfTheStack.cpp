#include<iostream>
#include<stack>
using namespace std;
//Iterative Approach
void InsertAtBottom(stack<int>&s,int x){
           stack<int>s2;
           while(!s.empty()){
              s2.push(s.top());
              s.pop();
           }
           s.push(x);
           while(!s2.empty()){
              s.push(s2.top());
              s2.pop();
           }
}
//Recursive Approach 
void InsertATBottom(stack<int>&s,int x){
       if(s.empty()){
          s.push(x);
          return;
       }
       int num=s.top();
       s.pop();
       InsertATBottom(s,x);
       s.push(num);
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    //InsertAtBottom(st,90);
    InsertATBottom(st, 78);

    cout << "Stack from top to bottom: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}