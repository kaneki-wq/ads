
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int s, vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<long long> d(n, INF);
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        long long dist = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist != d[v])
            continue;

        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;

            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                pq.push({d[u], u});
            }
        }
    }

    return d;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;

        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;

    s--;
    a--;
    b--;
    f--;

    vector<long long> ds = dijkstra(s, g);
    vector<long long> da = dijkstra(a, g);
    vector<long long> db = dijkstra(b, g);

    long long ans = INF;

    if (ds[a] != INF && da[b] != INF && db[f] != INF)
        ans = min(ans, ds[a] + da[b] + db[f]);

    if (ds[b] != INF && db[a] != INF && da[f] != INF)
        ans = min(ans, ds[b] + db[a] + da[f]);

    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
