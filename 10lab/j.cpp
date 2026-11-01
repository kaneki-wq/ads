
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> parent, children;

void dfs(int v, int p) {
    parent[v] = p;

    for (int to : g[v]) {
        if (to == p)
            continue;

        children[v]++;
        dfs(to, v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    parent.assign(n + 1, -1);
    children.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1)
            continue;

        vector<int> component;
        queue<int> q;
        q.push(i);
        parent[i] = i;
        int root = i;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            component.push_back(v);
            root = min(root, v);

            for (int to : g[v]) {
                if (parent[to] == -1) {
                    parent[to] = i;
                    q.push(to);
                }
            }
        }

        for (int v : component)
            parent[v] = -1;

        dfs(root, 0);
    }

    int ans = 0;

    for (int v = 1; v <= n; v++) {
        if (parent[v] == 0 ||
            children[v] > children[parent[v]]) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
