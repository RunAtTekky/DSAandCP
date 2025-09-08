#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a,b; cin >> a >> b;

    if (a < b) swap(a,b);

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    if (a % b == 0) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

