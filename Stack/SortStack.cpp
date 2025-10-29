#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int>&st,int element){
     //base case
     if(st.empty()||(!st.empty()&&st.top()<=element)){
        st.push(element);
        return;
     }
     int n=st.top();
     st.pop();
     insertSorted(st,element);
     st.push(n);
}
void SortStack(stack<int>&st){
    //base case 
    if(st.empty()) return;
    int num=st.top();
    st.pop();
    SortStack(st);
    insertSorted(st,num);
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(-2);
    st.push(4);
    st.push(9);

    //InsertAtBottom(st,90);
    SortStack(st);

    cout << "Stack from top to bottom: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}