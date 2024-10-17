#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int target; cin >> target;

    vector<long long> dp(target+1);

    dp[target] = 0;

    for (int i=target-1; i>=0; i--) {
        for (int j=i+1; (j<=target && j<=i+6); j++) {
            if (j==target) dp[i] = (dp[i] + 1) % MOD;
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    cout << dp[0] % MOD << "\n";

}

int main() {
    int t=1;
    while (t--) solve();
}
