#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> monsters(n);
    for (auto &monster : monsters) cin >> monster;

    vector<pair<ll,ll>> dp(n+1);
    dp[n-1].first = monsters[n-1] == 1;
    dp[n-1].second = 0;

    for (int i=n-2; i>=0; i--) {
        dp[i].first = min(monsters[i] + dp[i+1].second, monsters[i] + monsters[i+1] + dp[i+2].second);
        dp[i].second = min(dp[i+1].first, dp[i+2].first);
    }

    cout << dp[0].first << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

