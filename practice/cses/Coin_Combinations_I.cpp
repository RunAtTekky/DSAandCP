#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n, sum; cin >> n >> sum;

    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;

    sort(coins.begin(), coins.end());
    
    vector<long long> dp(sum+1);

    // dp[i] = sum( dp[i-coins[j]] ), 0<=j<n
    dp[0] = 1;

    for (int i=1; i<=sum; i++) {
        for (auto coin : coins) {
            if ((i-coin) < 0) break;

            dp[i] = (dp[i] + dp[i-coin]) % MOD;
        }
    }

    // for (int i=1; i<=sum; i++) {
    //     cout << i << " : " << dp[i] << "\n";
    // }

    cout << dp[sum] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
