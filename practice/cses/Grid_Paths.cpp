#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    // Take grid input
    for (int i=0; i<n; i++) { for (int j=0; j<n; j++) cin >> grid[i][j]; }

    if (grid[0][0] == '*') {cout << "0\n"; return;}

    vector<vector<long long>> dp(n+1, vector<long long>(n+1));

    // dp[row][col] = dp[row-1][col] + dp[row][col-1], row-1>=0 && col-1>=0
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '*') continue;

            if (i-1>=0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            if (j-1>=0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
