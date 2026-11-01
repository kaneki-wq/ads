#include <bits/stdc++.h>
using namespace std;

bool can(vector<double>& a, double x, int k) {
    int pieces = 0;

    for (double rope : a) {
        pieces += (int)(rope / x);

        if (pieces >= k)
            return true;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> a(n);

    double r = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    double l = 0;

    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;

        if (can(a, mid, k)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(9) << l << '\n';

    return 0;
}