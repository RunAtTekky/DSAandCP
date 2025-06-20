#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n+1);
    for (int i=0; i<n; i++) cin >> vec[i+1];
    
    vector<ll> dp(n+1);
    for (int i=n; i>=1; i--) {
        for (int j=i+i; j<=n; j+=i) {
            if (vec[i] < vec[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) + 1 << "\n";


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
