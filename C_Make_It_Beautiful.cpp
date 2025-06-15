#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> to_inc;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll num = vec[i];
        ll mult = 1;

        for (int bit=0; bit<63; bit++) {
            if (num%2 == 0) to_inc.push_back(mult);
            else ans++;
            mult = mult << 1;
            num = num >> 1;
        }
        // while (num > 0) {
        // }
    }

    // cout << "already " << ans << "\n";

    // for (auto &ele : to_inc) cout << ele << " ";
    // cout << "\n";

    sort(to_inc.begin(), to_inc.end());
    
    for (auto &ele : to_inc) {
        if (ele <= k) k -= ele;
        else break;
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
