#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    long long n; cin >> n;

    vector<long long> dp(n+1);

    dp[0] = 1;

    for (int i=1; i<=n; i++) {
        for (int k=1; k<=6; k++) {
            if ((i-k) < 0) break;
            dp[i] = (dp[i] + dp[i-k]) % MOD;
        }
    }

    cout << dp[n] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
