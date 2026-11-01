#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] == x) {
            cout << "Yes";
            return 0;
        }

        if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << "No";

    return 0;
}