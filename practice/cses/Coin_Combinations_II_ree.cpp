#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
void solve() {
    int n,sum; cin >> n >> sum;
 
    vector<int> coins(n);
    for (auto &coin : coins) cin >> coin;
 
    sort(coins.begin(), coins.end());
    
    // vector<vector<int>> dp(sum+1, vector<int>(n+1));
    int dp[sum+1][n+1];
    memset(dp, 0, sizeof dp);
 
    for (int j=0; j<n; j++) {
        dp[sum][j] = 1;
    }

    for (int i=sum; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if ( (i + coins[j]) > sum) continue;
 
            if ( (j+1) < n) {
                dp[i][j] = (dp[i][j] + dp[i + coins[j]][j]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i][j+1]) % MOD;
            }
            else {
                dp[i][j] = (dp[i][j] + dp[i + coins[j]][j]) % MOD;
            }
        }
    }
 
    cout << dp[0][0] << "\n";
 
    // for (int i=0; i<=sum; i++) cout << i << " \n"[i==sum];
 
    // for (int j=0; j<n; j++) {
    //     for (int i=0; i<=sum; i++) {
    //         cout << dp[i][j] << " \n"[i==sum];
    //     }
    // }
 
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}