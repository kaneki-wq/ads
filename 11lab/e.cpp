
#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<bool> active;

int find(int v) {
    if (p[v] == v) return v;
    return p[v] = find(p[v]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    p[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    p.resize(n + 1);
    active.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    vector<int> ans(n + 1);
    int components = 0;

    for (int i = n; i >= 1; i--) {
        ans[i] = components;

        active[i] = true;
        components++;

        for (int u : g[i]) {
            if (active[u] && unite(i, u)) {
                components--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
