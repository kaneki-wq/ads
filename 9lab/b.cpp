#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, T;
    int K;
    cin >> s >> K >> T;

    int cnt = 0;
    int pos = 0;

    while ((pos = T.find(s, pos)) != string::npos) {
        cnt++;
        pos += s.size();
    }

    if (cnt >= K)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}