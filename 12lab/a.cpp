
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }

    vector<bool> active(n, false);
    vector<int> ans(n);

    for (int t = 0; t < n; t++) {
        int k = x[t];
        active[k] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }

        int longest = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (active[i] && active[j]) {
                    longest = max(longest, d[i][j]);
                }
            }
        }

        ans[t] = longest;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << '\n';

    return 0;
}
