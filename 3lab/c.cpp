#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> end(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;
        end[i] = sum;
    }

    while (m--) {
        int line;
        cin >> line;

        int pos = lower_bound(end.begin(), end.end(), line) - end.begin();

        cout << pos + 1 << '\n';
    }

    return 0;
}