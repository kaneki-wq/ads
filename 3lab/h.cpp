#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pref[i + 1] = pref[i] + x;
    }

    int ans = n; 

    for (int l = 0; l < n; l++) {
        auto it = lower_bound(pref.begin() + l + 1, pref.end(),
                              pref[l] + k);

        if (it != pref.end()) {
            int r = it - pref.begin() - 1;
            ans = min(ans, r - l + 1);
        }
    }

    cout << ans << '\n';
}