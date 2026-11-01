#include <bits/stdc++.h>
using namespace std;

int countRange(vector<int>& a, int l, int r) {
    return upper_bound(a.begin(), a.end(), r)
         - lower_bound(a.begin(), a.end(), l);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int ans = countRange(a, l1, r1)
                + countRange(a, l2, r2);

        int left = max(l1, l2);
        int right = min(r1, r2);

        if (left <= right) {
            ans -= countRange(a, left, right);
        }

        cout << ans << '\n';
    }

    return 0;
}