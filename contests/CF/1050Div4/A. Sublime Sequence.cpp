#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll x, n; cin >> x >> n;

    if (n % 2 == 0) {
        cout << 0 << "\n";
    } else {
        cout << x << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

