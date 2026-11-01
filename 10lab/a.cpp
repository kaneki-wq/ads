#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            if (a[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<int>> dist(m, vector<int>(n, 0));
    int ans = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (a[nx][ny] != 1)
                continue;

            a[nx][ny] = 2;
            dist[nx][ny] = dist[x][y] + 1;

            ans = max(ans, dist[nx][ny]);

            q.push({nx, ny});
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}