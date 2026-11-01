
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int start, finish;
    cin >> start >> finish;

    start--;
    finish--;

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[finish] << '\n';

    return 0;
}
