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

void solve(Node* root, long long& sum, vector<long long>& answer) {
    if (root == nullptr)
        return;

    solve(root->right, sum, answer);

    sum += root->value;
    answer.push_back(sum);

    solve(root->left, sum, answer);
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

    long long sum = 0;
    vector<long long> answer;

    solve(root, sum, answer);

    for (long long x : answer)
        cout << x << ' ';

    cout << '\n';
}