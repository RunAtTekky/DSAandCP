#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x; cin >> n >> x;

    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;

    sort(coins.begin(), coins.end());

    vector<int> dp(x+1, 1e8);
    dp[x] = 0;

    for (int i=x; i>0; i--) {
        for (auto coin : coins) {
            if (i-coin < 0) break;
            dp[i-coin] = min(dp[i]+1, dp[i-coin]);
        }
    }

    if (dp[0] == 1e8) cout << "-1\n";
    else cout << dp[0] << "\n";
}

int main() {
    int t=1;
    while (t--) solve();
}
