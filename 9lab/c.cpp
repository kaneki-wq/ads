#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string s = b + b;

    int pos = s.find(a);

    if (pos == string::npos || pos >= b.size())
        cout << -1;
    else
        cout << pos;

    return 0;
}