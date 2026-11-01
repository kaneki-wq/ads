#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* reversed_node(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node dummy{0};
    Node* tail = &dummy;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        tail->next = new Node{x};
        tail = tail->next;
    }

    Node* rev_head = reversed_node(dummy.next);

    Node* cur = rev_head;

    while (cur != nullptr) {
        cout << cur->value << ' ';
        
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    cout << '\n';
    return 0;
}
