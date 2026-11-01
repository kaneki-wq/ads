#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return new Node{x};

    if (x < root->value)
        root->left = insert(root->left, x);
    else if (x > root->value)
        root->right = insert(root->right, x);

    return root;
}

int diameter(Node* root, int& answer) {
    if (root == nullptr)
        return 0;

    int left = diameter(root->left, answer);
    int right = diameter(root->right, answer);

    // Максимальный путь, проходящий через root
    answer = max(answer, left + right + 1);

    // Максимальный путь вниз от root
    return 1 + max(left, right);
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

    int answer = 0;

    diameter(root, answer);

    cout << answer << '\n';

    return 0;
}