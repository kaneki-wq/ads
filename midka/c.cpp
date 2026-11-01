
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    bool first = true;
    int last = 0;

    while (i < n || j < m) {
        int x;

        if (i == n) {
            x = b[j++];
        } else if (j == m) {
            x = a[i++];
        } else if (a[i] < b[j]) {
            x = a[i++];
        } else if (b[j] < a[i]) {
            x = b[j++];
        } else {
            x = a[i];
            i++;
            j++;
        }

        if (first || x != last) {
            if (!first) cout << ' ';
            cout << x;
            last = x;
            first = false;
        }
    }

    cout << '\n';
    return 0;
}
