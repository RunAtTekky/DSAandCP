#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

typedef long long ll;

ll nC2(ll n) {
    return ((n) * (n-1) / 2) % MOD;
}

ll perm(ll x) {
    ll ans = 1;
    for (int i=1; i<=x; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}


void solve() {
    int n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    ll mini = *min_element(vec.begin(), vec.end());

    ll min_count = count(vec.begin(), vec.end(), mini);
    if (min_count == 1) {cout << "0\n"; return;}

    for (auto x : vec) {
        if ((x & mini) != mini) {
            cout << "0\n"; return;
        }
    }

    ll ans = 2*nC2(min_count) * perm(n-2);

    cout << ans%MOD << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
