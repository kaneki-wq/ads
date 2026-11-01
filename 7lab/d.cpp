
#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return 0;

    int m = (l + r) / 2;

    long long cnt = 0;
    cnt += mergeSort(a, l, m);
    cnt += mergeSort(a, m + 1, r);

    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
            cnt += m - i + 1;
        }
    }

    while (i <= m) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        a[l + k] = temp[k];
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << mergeSort(a, 0, n - 1) << "\n";

    return 0;
}
