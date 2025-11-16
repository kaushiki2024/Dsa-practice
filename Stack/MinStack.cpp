#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
    
public:
    void push(int val) {
        st.push(val);
        // If min stack is empty OR new value <= current min
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());  // repeat current minimum
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack ms;

  
    ms.push(5);
    cout << "Pushed: 5, Min: " << ms.getMin() << endl;

    ms.push(2);
    cout << "Pushed: 2, Min: " << ms.getMin() << endl;

    ms.push(4);
    cout << "Pushed: 4, Min: " << ms.getMin() << endl;

    ms.push(1);
    cout << "Pushed: 1, Min: " << ms.getMin() << endl;

    ms.pop();
    cout << "After pop, Min: " << ms.getMin() << endl;

    ms.push(3);
    cout << "Pushed: 3, Min: " << ms.getMin() << endl;

    cout << "Top element: " << ms.top() << endl;
    cout << "Final Min: " << ms.getMin() << endl;

    return 0;
}
