
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int findDepth(Node* root, int x, int depth) {
    if (root->val == x)
        return depth;

    if (x < root->val)
        return findDepth(root->left, x, depth + 1);
    else
        return findDepth(root->right, x, depth + 1);
}

int main() {
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

    cout << findDepth(root, x, 0) << '\n';

    return 0;
}
