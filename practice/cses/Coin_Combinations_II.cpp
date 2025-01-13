#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n,sum; cin >> n >> sum;

    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;

    sort(coins.begin(), coins.end());

    vector<long long> dp(sum+1);

    // dp[w] = number of distinct ways to make sum w

    dp[0] = 1;
    // There is only one way to make sum = w = 0. Take no coin.

    // We will go through each coin starting from lowest possible.
    for (int i=0; i<n; i++) {
        for (int current_sum=coins[i]; current_sum<=sum; current_sum++) {
            dp[current_sum] = dp[current_sum] + dp[current_sum - coins[i]];
            dp[current_sum] %= MOD;
        }
    }

    cout << dp[sum] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
