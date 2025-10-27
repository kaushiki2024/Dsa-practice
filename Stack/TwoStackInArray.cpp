#include<iostream>
using namespace std;
class TwoStacks{
     int* arr;
     int top1,top2;
     int size;
     //constructor
     public:
       TwoStacks(int n){
            size=n;
            arr= new int[n];
            top1=-1;
            top2=size;           
       }
       void push1(int x){
              if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow on Stack 1\n";
        }
       }
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow on Stack 2\n";
        }
    }
        // Pop from stack1
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            cout << "Stack Underflow on Stack 1\n";
            return -1;
        }
    }

    // Pop from stack2
    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            cout << "Stack Underflow on Stack 2\n";
            return -1;
        }
    }
};
int main() {
    TwoStacks ts(10);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);

    cout << "Popped from stack1: " << ts.pop1() << endl;
    cout << "Popped from stack2: " << ts.pop2() << endl;

    return 0;
}