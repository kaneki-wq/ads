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

    queue<Node*> q;
    q.push(root);

    vector<long long> sums;

    while (!q.empty()) {
        int sz = q.size();
        long long sum = 0;

        for (int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();

            sum += cur->value;

            if (cur->left != nullptr)
                q.push(cur->left);

            if (cur->right != nullptr)
                q.push(cur->right);
        }

        sums.push_back(sum);
    }

    cout << sums.size() << '\n';

    for (long long x : sums)
        cout << x << ' ';

    cout << '\n';

    return 0;
}