
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    const long long INF = LLONG_MAX;
    vector<long long> d(n, INF);
    vector<bool> used(n, false);

    d[0] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (v == -1 || d[v] == INF)
            break;

        used[v] = true;

        for (int u = 0; u < n; u++) {
            long long w = abs(x[v] - x[u]) + abs(y[v] - y[u]);
            long long nd = max(d[v], w);

            if (nd < d[u])
                d[u] = nd;
        }
    }

    cout << d[n - 1] << '\n';

    return 0;
}
