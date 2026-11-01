
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> rail(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        rail[u][v] = true;
        rail[v][u] = true;
    }

    bool direct = rail[0][n - 1];

    vector<int> d(n, -1);
    queue<int> q;

    d[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            if (u == v || d[u] != -1)
                continue;

            bool edge = direct ? !rail[v][u] : rail[v][u];

            if (edge) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    cout << d[n - 1] << '\n';

    return 0;
}
