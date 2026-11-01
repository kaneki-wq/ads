#include <bits/stdc++.h>
using namespace std;

bool can(vector<long long>& a, long long k, long long h) {
    long long hours = 0;

    for (long long x : a) {
        hours += (x + k - 1) / k;

        if (hours > h)
            return false;
    }

    return true;
}

int main() {
    int n;
    long long h;

    cin >> n >> h;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long l = 1;
    long long r = *max_element(a.begin(), a.end());

    while (l < r) {
        long long mid = l + (r - l) / 2;

        if (can(a, mid, h)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';

    return 0;
}