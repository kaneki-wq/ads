#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
}

Node* insert(Node* root, int x) {
    if (root == nullptr) {
        return new Node{x};
    }

    if (x < root->value)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int getSize(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + getSize(root->left) + getSize(root->right);
}

Node* find(Node* root, int x) {
    if (root == nullptr || root->value == x)
        return root;

    if (x < root->value)
        return find(root->left, x);
    else
        return find(root->right, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int x;
    cin >> x;

    Node* target = find(root, x);

    cout << getSize(target) << '\n';

    return 0;
}