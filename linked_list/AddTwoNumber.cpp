#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution using dummy node
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = 0;
            int v2 = 0;

            if (l1 != nullptr) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;  // skip dummy node
    }
};

// Helper to create a linked list from digits
ListNode* createList(initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : values) {
        if (!head) {
            head = new ListNode(v);
            tail = head;
        } else {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
    }
    return head;
}

// Helper to print a list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 342 = 2 -> 4 -> 3
    ListNode* l1 = createList({2, 4, 3});

    // Example: 465 = 5 -> 6 -> 4
    ListNode* l2 = createList({5, 6, 4});

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    cout << "Result: ";
    printList(result);

    return 0;
}
