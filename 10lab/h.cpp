
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    if (a[x][y] == '0')
        return;

    a[x][y] = '0';

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    cin >> n >> m;

    a.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
