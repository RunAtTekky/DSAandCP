#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, target; cin >> n >> target;

    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;

    sort(coins.begin(), coins.end());

    vector<long long> dp(target+1);

    // dp[i] = 1 + min({ dp[i-coins[j]] }), where 0 <= j < m, m = size of coins array
    for (int i=1; i<=target; i++) {
        long long minimum_coins_behind = INT_MAX;
        for (auto coin : coins) {
            if ((i-coin) < 0) break;

            minimum_coins_behind = min(minimum_coins_behind, dp[i-coin]);
        }
        dp[i] = minimum_coins_behind + 1;
    }

    cout <<( (dp[target] == (1LL+INT_MAX)) ? -1 : dp[target] ) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
