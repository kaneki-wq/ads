#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    vector<long long> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (long long x : queries) {
        int l = 0;
        int r = n - 1;
        int row = -1;

        // Ищем строку
        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long mn = min(a[mid][0], a[mid][m - 1]);
            long long mx = max(a[mid][0], a[mid][m - 1]);

            if (mn <= x && x <= mx) {
                row = mid;
                break;
            }

            // Следующие строки содержат меньшие числа
            if (x > mx) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (row == -1) {
            cout << -1 << '\n';
            continue;
        }

        // Ищем внутри строки
        int left = 0;
        int right = m - 1;
        int col = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (a[row][mid] == x) {
                col = mid;
                break;
            }

            if (row % 2 == 1) {
                // возрастающая строка
                if (a[row][mid] < x)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                // убывающая строка
                if (a[row][mid] > x)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        if (col == -1)
            cout << -1 << '\n';
        else
            cout << row << ' ' << col << '\n';
    }
}