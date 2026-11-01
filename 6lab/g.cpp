#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> users;    // original -> current
    map<string, string> current;  // current -> original

    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;

        if (current.count(oldNick)) {
            // Этот пользователь уже менял ник
            string original = current[oldNick];

            users[original] = newNick;

            current.erase(oldNick);
            current[newNick] = original;
        }
        else {
            // Новый пользователь
            users[oldNick] = newNick;
            current[newNick] = oldNick;
        }
    }

    cout << users.size() << '\n';

    for (auto [original, now] : users) {
        cout << original << ' ' << now << '\n';
    }
}