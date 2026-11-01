#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> a(n);

    for (char &c : a)
        cin >> c;

    char k;
    cin >> k;

    auto it = upper_bound(a.begin(), a.end(), k);

    if (it == a.end())
        cout << a[0] << '\n';
    else
        cout << *it << '\n';
}