#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;

    ll n = s.size();
    map<ll,ll> dp;

    ll before_last_b = 0;
    for (int i=0; i<n; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            dp[i+1] = dp[i];
        } else if (s[i] == 'b') {
            before_last_b = dp[i];
            dp[i+1] = dp[i];
        } else {
            dp[i+1] = (dp[i] + 1LL) % MOD;
            dp[i+1] = (dp[i+1] + before_last_b) % MOD;
        }
    }

    cout << dp[n] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

