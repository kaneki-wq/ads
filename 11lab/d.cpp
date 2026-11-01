
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

vector<int> p;

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
    int n;
    cin >> n;

    vector<Edge> edges;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;

            if (j > i) {
                edges.push_back({i, j, cost});
            }
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.cost < b.cost;
         });

    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    int ans = 0;

    for (Edge e : edges) {
        if (unite(e.a, e.b)) {
            ans += e.cost;
        }
    }

    cout << ans << '\n';

    return 0;
}
