#include <bits/stdc++.h>
using namespace std;

const int MAX_HEIGHT = 1e6;
const int MOD = 1e9+7;

vector<vector<long long>> dp;

void precompute() {

    // Base Case
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i=2; i<=MAX_HEIGHT; i++) {
        dp[i][0] = (2 * dp[i-1][0]) % MOD + dp[i-1][1];
        dp[i][0] %= MOD;
        dp[i][1] = (4 * dp[i-1][1]) % MOD + dp[i-1][0];
        dp[i][1] %= MOD;
    }

}

void solve() {
    long long n; cin >> n;

    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    dp = vector<vector<long long>>(MAX_HEIGHT+1, vector<long long>(2));
    precompute();

    int t=1; cin >> t;
    while (t--) solve();
}
