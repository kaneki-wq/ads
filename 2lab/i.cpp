#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }

    Node* cur = head;
    for (int i = 0; i < p - 1; ++i)
        cur = cur->next;

    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < p - 1; ++i)
        cur = cur->next;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;

    return head;
}

Node* replace(Node* head, int p1, int p2) {
    Node* node;

    if (p1 == 0) {
        node = head;
        head = head->next;
    }
    else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1; ++i)
            cur = cur->next;

        node = cur->next;
        cur->next = node->next;
    }

    if (p2 == 0) {
        node->next = head;
        return node;
    }

    Node* cur = head;
    for (int i = 0; i < p2 - 1; ++i)
        cur = cur->next;

    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* reverse(Node* head) {
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

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << '\n';
        return;
    }

    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->value << " ";
        cur = cur->next;
    }

    cout << '\n';
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int c = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        c++;
    }

    x %= c;
    if (x == 0) return head;

    Node* newTail = head;

    for (int i = 1; i < x; ++i)
        newTail = newTail->next;

    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int c = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        c++;
    }

    x %= c;
    if (x == 0) return head;

    int left = c - x;

    Node* newTail = head;

    for (int i = 1; i < left; ++i)
        newTail = newTail->next;

    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    while (true) {
        int command;
        cin >> command;

        if (command == 0) break;

        else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node{x}, p);
        }

        else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        }

        else if (command == 3) {
            print(head);
        }

        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }

        else if (command == 5) {
            head = reverse(head);
        }

        else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }

        else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
