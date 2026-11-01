
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n);
    int l = 0, r = n - 1;

    for (int k = n - 1; k >= 0; k--) {
        if (abs(a[l]) > abs(a[r])) {
            ans[k] = a[l] * a[l];
            l++;
        } else {
            ans[k] = a[r] * a[r];
            r--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
