
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* p = new Node(x);

        if (head == nullptr) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->val << '\n';

    return 0;
}
