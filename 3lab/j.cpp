#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> need(n);

    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        need[i] = max(x2, y2);
    }

    sort(need.begin(), need.end());

    cout << need[k - 1] << '\n';
}