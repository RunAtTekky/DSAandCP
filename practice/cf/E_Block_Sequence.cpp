#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    vector<ll> dp(n+1);

    for (int i=n-1; i>=0; i--) {
        ll pos = i + vec[i] + 1;

        if (pos > n) {
            dp[i] = dp[i+1] + 1;
        } else {
            dp[i] = min(dp[i+1] + 1, dp[pos]);
        }
    }

    cout << dp[0] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
