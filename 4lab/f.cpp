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
    else
        root->right = insert(root->right, x);

    return root;
}

int countTriangles(Node* root) {
    if (root == nullptr)
        return 0;

    int answer = 0;

    if (root->left != nullptr && root->right != nullptr)
        answer++;

    answer += countTriangles(root->left);
    answer += countTriangles(root->right);

    return answer;
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

    cout << countTriangles(root) << '\n';

    return 0;
}