
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);

    while (q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            if (dist[v] == 0)
                continue;

            dist[v] = 0;
            queue<int> qu;
            qu.push(v);

            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();

                for (int to : g[u]) {
                    if (dist[to] == -1 ||
                        dist[to] > dist[u] + 1) {
                        dist[to] = dist[u] + 1;
                        qu.push(to);
                    }
                }
            }
        } else {
            cout << dist[v] << '\n';
        }
    }

    return 0;
}
