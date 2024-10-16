#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s,t;
    cin >> s >> t;

    int samePrefixLength = 0;

    int n = min(s.size(), t.size());

    int i;
    for (i=0; i<n; i++) {
        if (s[i] == t[i]) samePrefixLength++;
        else break;
    }

    int total = samePrefixLength + (samePrefixLength != 0);

    total += t.size() - i;
    total += s.size() - i;

    cout << total << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}