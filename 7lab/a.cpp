
#include <bits/stdc++.h>
using namespace std;

void merge(vector<string>& a, int l, int m, int r) {
    vector<string> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i].size() <= a[j].size()) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
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
}

void mergeSort(vector<string>& a, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

int main() {
    int T;
    cin >> T;
    string s;
    getline(cin, s);

    while (T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> a;

        while (ss >> s) {
            a.push_back(s);
        }

        mergeSort(a, 0, (int)a.size() - 1);

        for (int i = 0; i < a.size(); i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }

    return 0;
}
