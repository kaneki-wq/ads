
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : g[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)order.size() != n) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";

        for (int i = 0; i < n; i++) {
            cout << order[i];

            if (i + 1 < n) {
                cout << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}
