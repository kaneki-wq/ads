#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

int leaves = 0;

Node* insert(Node* root, int x) {
    if (root == nullptr) {
        leaves++; // новая вершина является листом
        return new Node{x};
    }

    // Если root сейчас лист, после добавления ребёнка он перестанет быть листом
    if (root->left == nullptr && root->right == nullptr) {
        leaves--;
    }

    if (x < root->value)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
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

    cout << leaves << '\n';
}