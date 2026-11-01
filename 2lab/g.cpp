#include <bits/stdc++.h>
using namespace std;

struct Node {
    string value;
    Node* next = nullptr;
};

Node* cyclic_shift(Node* head, int x, int n) {
    if (n == 0) return head;

    x %= n;

    if (x == 0) return head;

    Node* tail = head;

    while (tail->next != nullptr)
        tail = tail->next;

    Node* cur = head;

    for (int i = 1; i < x; ++i)
        cur = cur->next;

    Node* newTail = cur;
    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Node dummy{""};
    Node* tail = &dummy;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        tail->next = new Node{word};
        tail = tail->next;
    }

    Node* shifted_node = cyclic_shift(dummy.next, k, n);

    Node* cur = shifted_node;

    while (cur != nullptr) {
        cout << cur->value << " ";

        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    cout << '\n';
    return 0;
}
