#include <bits/stdc++.h>
using namespace std;

struct Node {
    string value;
    Node* next = nullptr;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node dummy{""};
    Node* tail = &dummy;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        tail->next = new Node{name};
        tail = tail->next;
    }

    Node* cur = dummy.next;

    while (cur != nullptr && cur->next != nullptr) {
        if (cur->value == cur->next->value) {
            Node* del = cur->next;
            cur->next = del->next;
            delete del;
        }
        else {
            cur = cur->next;
        }
    }

    int counter = 0;
    cur = dummy.next;

    while (cur != nullptr) {
        counter++;
        cur = cur->next;
    }

    cout << counter << '\n';

    cur = dummy.next;

    while (cur != nullptr) {
        Node* temp = cur;
        cout << cur->value << '\n';
        cur = cur->next;
        delete temp;
    }

    return 0;
}
