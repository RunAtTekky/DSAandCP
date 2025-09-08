#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> cakes(n);
    for (auto &cake : cakes) cin >> cake;

    sort(cakes.begin(), cakes.end());

    ll total_cakes = 0;
    for (ll i=m, j=n-1; i>=1 && j>=0; i--, j--) {
        total_cakes += cakes[j] * i;
    }

    cout << total_cakes << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

