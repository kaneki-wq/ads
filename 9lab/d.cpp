#include <bits/stdc++.h>
using namespace std;

int main() {
    string P;
    cin >> P;

    int N;
    cin >> N;

    vector<string> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (char &c : P)
        c = tolower(c);

    vector<int> len(N, 0);
    int best = 0;

    for (int i = 0; i < N; i++) {
        string city = a[i];

        for (char &c : city)
            c = tolower(c);

        int mx = min(P.size(), city.size());

        for (int k = mx; k > 0; k--) {
            if (P.substr(P.size() - k) == city.substr(0, k)) {
                len[i] = k;
                break;
            }
        }

        best = max(best, len[i]);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (len[i] == best && best > 0)
            cnt++;
    }

    cout << cnt << '\n';

    for (int i = 0; i < N; i++) {
        if (len[i] == best && best > 0)
            cout << a[i] << '\n';
    }

    return 0;
}