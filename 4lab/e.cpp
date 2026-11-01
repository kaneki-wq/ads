#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int parent, child, side;
        cin >> parent >> child >> side;

        if (side == 0)
            left[parent] = child;
        else
            right[parent] = child;
    }

    queue<int> q;
    q.push(1);

    int answer = 0;

    while (!q.empty()) {
        int width = q.size();

        answer = max(answer, width);

        for (int i = 0; i < width; i++) {
            int v = q.front();
            q.pop();

            if (left[v] != 0)
                q.push(left[v]);

            if (right[v] != 0)
                q.push(right[v]);
        }
    }

    cout << answer << '\n';

    return 0;
}