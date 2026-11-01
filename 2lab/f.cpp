#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* merge(Node* cur1, Node* cur2) {
    Node dummy{0};
    Node* tail = &dummy;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->value <= cur2->value) {
            tail->next = cur1;
            cur1 = cur1->next;
        }
        else {
            tail->next = cur2;
            cur2 = cur2->next;
        }

        tail = tail->next;
    }

    if (cur1 != nullptr)
        tail->next = cur1;
    else
        tail->next = cur2;

    return dummy.next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    cin >> n1;

    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;

        Node* node = new Node{x};

        if (head1 == nullptr)
            head1 = node;
        else
            tail1->next = node;

        tail1 = node;
    }

    cin >> n2;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;

        Node* node = new Node{x};

        if (head2 == nullptr)
            head2 = node;
        else
            tail2->next = node;

        tail2 = node;
    }

    Node* head = merge(head1, head2);

    Node* cur = head;

    while (cur != nullptr) {
        cout << cur->value << " ";

        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    cout << '\n';
    return 0;
}
