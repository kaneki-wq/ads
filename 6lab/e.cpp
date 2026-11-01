#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++) {
        vector<int> column;

        for (int i = 0; i < n; i++)
            column.push_back(a[i][j]);

        sort(column.rbegin(), column.rend());

        for (int i = 0; i < n; i++)
            a[i][j] = column[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}