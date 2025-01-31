#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l,r; cin >> l >> r;

    if (l == r && l == 1) {
        cout << "1\n"; return;
    }

    cout << r - l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
