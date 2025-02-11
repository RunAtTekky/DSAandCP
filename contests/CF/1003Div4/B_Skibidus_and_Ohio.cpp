#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;

    int n = s.size();

    for (int i=0; i+1<n; i++) {
        if (s[i] == s[i+1]) {
            cout << "1\n"; return;
        }
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
