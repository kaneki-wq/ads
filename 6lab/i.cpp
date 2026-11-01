#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[26] = {};

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        while (cnt[i] > 0) {
            cout << char('a' + i);
            cnt[i]--;
        }
    }

    cout << '\n';
}