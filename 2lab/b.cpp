#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

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

    Node* cur = dummy.next;

    while (cur != nullptr && cur->next != nullptr) {
        Node* del = cur->next;
        cur->next = del->next;
        delete del;
    }

    cur = dummy.next;

    while (cur != nullptr) {
        cout << cur->value << ' ';

        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    cout << '\n';
    return 0;
}
