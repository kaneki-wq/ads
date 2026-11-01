#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

int kadaneSum(Node* head) {
    int currSum = head->value;
    int maxSum = head->value;

    Node* cur = head->next;

    while (cur != nullptr) {
        currSum = max(cur->value, currSum + cur->value);
        maxSum = max(maxSum, currSum);
        cur = cur->next;
    }

    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node dummy{0};
    Node* tail = &dummy;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        tail->next = new Node{x};
        tail = tail->next;
    }

    cout << kadaneSum(dummy.next) << '\n';

    Node* cur = dummy.next;

    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}