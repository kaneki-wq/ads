#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    long long l = 0;
    long long r = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    auto can = [&](long long x) {
        int parts = 1;
        long long sum = 0;

        for (long long v : a) {
            if (sum + v <= x) {
                sum += v;
            } else {
                parts++;
                sum = v;
            }
        }

        return parts <= k;
    }

    while (l < r) {
        long long mid = l + (r - l) / 2;

        if (can(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}