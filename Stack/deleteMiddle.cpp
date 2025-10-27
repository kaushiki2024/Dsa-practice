#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    // base case: middle element reached
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, count + 1, size);

    // push the element back after recursion(middle element is removed)
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original stack : 5 4 3 2 1" << endl;

    deleteMiddle(st, st.size());

    cout << "After deleting middle element: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
