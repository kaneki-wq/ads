
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> color, parent;
vector<pair<int, int>> cycle;

bool dfs(int v) {
    color[v] = 1;

    for (int to : g[v]) {
        if (color[to] == 0) {
            parent[to] = v;

            if (dfs(to))
                return true;
        } else if (color[to] == 1) {
            cycle.push_back({v, to});

            int x = v;
            while (x != to) {
                cycle.push_back({parent[x], x});
                x = parent[x];
            }

            return true;
        }
    }

    color[v] = 2;
    return false;
}

bool acyclic(int skipU, int skipV) {
    vector<int> deg(n + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (u == skipU && v == skipV)
                continue;
            deg[v]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;

        for (int v : g[u]) {
            if (u == skipU && v == skipV)
                continue;

            deg[v]--;

            if (deg[v] == 0)
                q.push(v);
        }
    }

    return cnt == n;
}

int main() {
    cin >> n >> m;

    g.resize(n + 1);
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(i))
            break;
    }

    if (cycle.empty()) {
        cout << "YES\n";
        return 0;
    }

    for (auto e : cycle) {
        if (acyclic(e.first, e.second)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
