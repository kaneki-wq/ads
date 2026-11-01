
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A == B) {
        cout << 0 << '\n' << '\n';
        return 0;
    }

    int limit = 2 * max(A, B);

    vector<int> dist(limit + 1, -1);
    vector<int> parent(limit + 1, -1);
    queue<int> q;

    q.push(A);
    dist[A] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int y = x * 2;

        if (y <= limit && dist[y] == -1) {
            dist[y] = dist[x] + 1;
            parent[y] = x;
            q.push(y);
        }

        y = x - 1;

        if (y >= 0 && dist[y] == -1) {
            dist[y] = dist[x] + 1;
            parent[y] = x;
            q.push(y);
        }

        if (dist[B] != -1)
            break;
    }

    vector<int> path;
    int cur = B;

    while (cur != A) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << dist[B] << '\n';

    for (int x : path) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
