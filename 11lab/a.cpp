
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int l, r;
    long long c;
};

vector<int> p, nxt;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    p[a] = b;
    return true;
}

int getNext(int x) {
    if (nxt[x] == x) return x;
    return nxt[x] = getNext(nxt[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].l >> edges[i].r >> edges[i].c;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.c < b.c;
         });

    p.resize(n + 1);
    nxt.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        nxt[i] = i;
    }

    long long ans = 0;

    for (const Edge& e : edges) {
        int i = getNext(e.l);

        while (i < e.r) {
            if (unite(i, i + 1)) {
                ans += e.c;
            }

            nxt[i] = getNext(i + 1);
            i = getNext(i);
        }
    }

    cout << ans << '\n';

    return 0;
}
