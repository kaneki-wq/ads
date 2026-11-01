#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    priority_queue<long long> pq;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long ans = 0;

    for (int i = 0; i < x; i++) {
        long long mx = pq.top();
        pq.pop();

        ans += mx;

        pq.push(mx - 1);
    }

    cout << ans << '\n';
}