#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> sum(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int x, int y) {
        if (sum[x] != sum[y]) {
            return sum[x] > sum[y];
        }
        return a[x] < a[y];
    });

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << " ";
            cout << a[order[i]][j];
        }
        cout << "\n";
    }

    return 0;
}