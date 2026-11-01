
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    vector<bool> used(n + 1, false);
    queue<int> q;

    q.push(s);
    used[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }

    if (used[f])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
