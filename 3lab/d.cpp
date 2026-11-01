#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // prefix[i] = сумма первых i элементов
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    int q;
    cin >> q;

    while (q--) {
        long long power;
        cin >> power;

        int cnt = upper_bound(a.begin(), a.end(), power) - a.begin();

        long long sum = prefix[cnt];

        cout << cnt << ' ' << sum << '\n';
    }

    return 0;
}