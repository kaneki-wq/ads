#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;

    while (pq.top() < m) {
        // Нужны два элемента, чтобы смешать их
        if (pq.size() < 2) {
            cout << -1 << '\n';
            return 0;
        }

        long long least = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        long long newDensity = least + 2 * second;

        pq.push(newDensity);
        ans++;
    }

    cout << ans << '\n';
}