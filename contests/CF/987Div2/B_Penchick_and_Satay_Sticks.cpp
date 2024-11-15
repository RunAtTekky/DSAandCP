#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &e : a) cin >> e;

    for (int i=0; i<n; i++) {
        int diff = abs(a[i] - i - 1);
        if (diff > 1) { cout << "NO\n"; return; }
    }

    cout << "YES\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
