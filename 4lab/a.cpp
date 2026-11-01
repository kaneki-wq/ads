#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> value(n);
    vector<int> left(n, -1);
    vector<int> right(n, -1);

    cin >> value[0];

    int nodes = 1;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        int cur = 0;

        while (true) {
            if (x <= value[cur]) {
                if (left[cur] == -1) {
                    left[cur] = nodes;
                    value[nodes] = x;
                    nodes++;
                    break;
                }
                cur = left[cur];
            } else {
                if (right[cur] == -1) {
                    right[cur] = nodes;
                    value[nodes] = x;
                    nodes++;
                    break;
                }
                cur = right[cur];
            }
        }
    }

    while (q--) {
        string s;
        cin >> s;

        int cur = 0;
        bool ok = true;

        for (char c : s) {
            if (c == 'L') {
                if (left[cur] == -1) {
                    ok = false;
                    break;
                }
                cur = left[cur];
            } else {
                if (right[cur] == -1) {
                    ok = false;
                    break;
                }
                cur = right[cur];
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}