#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string s = A;
    int cnt = 1;

    while (s.size() < B.size()) {
        s += A;
        cnt++;
    }

    if (s.find(B) != string::npos) {
        cout << cnt;
        return 0;
    }

    s += A;
    cnt++;

    if (s.find(B) != string::npos)
        cout << cnt;
    else
        cout << -1;

    return 0;
}