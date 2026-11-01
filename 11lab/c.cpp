
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long cost;
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
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;

        int price;

        if (type == "big") {
            price = x;
        } else if (type == "small") {
            price = y;
        } else {
            price = min(x, y);
        }

        edges[i] = {a, b, 1LL * c * price};
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.cost < b.cost;
         });

    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    long long ans = 0;
    int cnt = 0;

    for (Edge e : edges) {
        if (unite(e.a, e.b)) {
            ans += e.cost;
            cnt++;

            if (cnt == n - 1) break;
        }
    }

    cout << ans << '\n';

    return 0;
}
