#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;

    vector<vector<ll>> dp(k+1, vector<ll>(n+1));

    for (int i=1; i<=n; i++) { dp[k][i] = 1; }

    for (int i=k-1; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            for (int mult = j; mult <= n; mult += j) {
                dp[i][j] = (dp[i][j] + dp[i+1][mult]) % MOD;
            }
        }
    }

    ll sum = 0;
    for (int i=1; i<=n; i++) {
        sum = (sum + dp[1][i]) % MOD;
    }

    cout << sum << "\n";


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
