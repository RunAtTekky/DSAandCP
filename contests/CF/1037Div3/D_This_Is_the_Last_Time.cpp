#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, coins; cin >> n >> coins;

    vector<vector<ll>> casinos(n, vector<ll>(3));
    for (int i=0; i<n; i++) {
        cin >> casinos[i][0];
        cin >> casinos[i][1];
        cin >> casinos[i][2];
    }

    sort(casinos.begin(), casinos.end());
    // sort(casinos.begin(), casinos.end(), [&](vector<ll> x, vector<ll> y) {
    //     return x[0] <= y[0];
    // });

    for (auto &casino : casinos) {
        ll lft = casino[0], rgt = casino[1], real = casino[2];
        // cout << lft << " " << rgt << " " << real << "\n";
        if ( (lft <= coins) && (coins <= rgt) ) {
            coins = max(coins, real);
        }
    }

    cout << coins << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
