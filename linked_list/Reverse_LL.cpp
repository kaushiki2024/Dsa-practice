#include <iostream>
using namespace std;

struct ListNode {
    int d;
    ListNode *next;
    ListNode(int x) {
        d = x;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) return 0;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> x;

        ListNode* newNode = new ListNode(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next)
        cout << temp->d << " ";
    cout << endl;

    head = reverseList(head);

    cout << "Reversed list: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next)
        cout << temp->d << " ";
    cout << endl;
}
