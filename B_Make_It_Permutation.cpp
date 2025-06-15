#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    cout << (n-1) * 2 << "\n";

    for (int i=2; i<=n; i++) {
        cout << i << " " << 1 << " " << n << "\n";
        cout << i << " " << i << " " << n << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
