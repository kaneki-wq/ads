#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int mn = INT_MAX;

    // Сначала находим минимальную разницу
    for (int i = 1; i < n; i++) {
        mn = min(mn, a[i] - a[i - 1]);
    }

    // Потом выводим все пары с этой разницей
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == mn) {
            cout << a[i - 1] << ' ' << a[i] << ' ';
        }
    }

    cout << '\n';
}