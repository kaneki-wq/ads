
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int NO_EDGE = 100000;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<long long> d(n, 0);
    vector<int> parent(n, -1);

    int x = -1;

    for (int k = 0; k < n; k++) {
        x = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == NO_EDGE)
                    continue;

                if (d[j] > d[i] + a[i][j]) {
                    d[j] = d[i] + a[i][j];
                    parent[j] = i;
                    x = j;
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++)
        x = parent[x];

    vector<int> cycle;
    int v = x;

    do {
        cycle.push_back(v);
        v = parent[v];
    } while (v != x);

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << '\n';

    for (int v : cycle)
        cout << v + 1 << ' ';

    cout << '\n';

    return 0;
}
