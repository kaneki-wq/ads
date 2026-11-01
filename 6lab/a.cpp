#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt[26] = {};

    for (char c : s) {
        cnt[c - 'a']++;
    }

    string vowels = "aeiou";

    for (char c : vowels) {
        while (cnt[c - 'a'] > 0) {
            cout << c;
            cnt[c - 'a']--;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            continue;

        while (cnt[c - 'a'] > 0) {
            cout << c;
            cnt[c - 'a']--;
        }
    }

    cout << '\n';
}