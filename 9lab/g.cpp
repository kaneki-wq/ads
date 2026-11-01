#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    cout << n - pi[n - 1];

    return 0;
}