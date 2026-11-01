#include <bits/stdc++.h>
using namespace std;

int main() {
    string s2, s1;
    cin >> s2 >> s1;

    int n = s1.size();
    int m = s2.size();

    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s1[i] != s1[j]) {
            j = pi[j - 1];
        }

        if (s1[i] == s1[j]) {
            j++;
        }

        pi[i] = j;
    }

    vector<int> ans;
    int j = 0;

    for (int i = 0; i < m; i++) {
        while (j > 0 && s2[i] != s1[j]) {
            j = pi[j - 1];
        }

        if (s2[i] == s1[j]) {
            j++;
        }

        if (j == n) {
            ans.push_back(i - n + 2);
            j = pi[j - 1];
        }
    }

    cout << ans.size() << '\n';

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }

    cout << '\n';
    return 0;
}