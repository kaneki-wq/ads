
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    int sum = 0;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        mn = min(mn, d[i]);
    }

    if (n == 1) {
        cout << 0 << '\n';
    } else {
        cout << sum + (n - 2) * mn << '\n';
    }

    return 0;
}
