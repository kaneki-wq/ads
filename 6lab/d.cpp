#include <bits/stdc++.h>
using namespace std;

struct Date {
    int d, m, y;
};

int main() {
    int n;
    cin >> n;

    vector<Date> a(n);

    for (int i = 0; i < n; i++) {
        char c;
        cin >> a[i].d >> c >> a[i].m >> c >> a[i].y;
    }

    sort(a.begin(), a.end(), [](Date x, Date y) {
        if (x.y != y.y) return x.y < y.y;
        if (x.m != y.m) return x.m < y.m;
        return x.d < y.d;
    });

    for (Date x : a) {
        cout << setfill('0') << setw(2) << x.d << '-'
             << setw(2) << x.m << '-'
             << setw(4) << x.y << '\n';
    }
}