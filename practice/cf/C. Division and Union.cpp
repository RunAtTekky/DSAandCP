#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> segments;
    for (int i=0; i<n; i++) {
        ll l,r; cin >> l >> r;
        segments.push_back({l,r,i});
    }

    sort(segments.begin(), segments.end());

    ll mx = segments[0][0];

    vector<ll> ans(n);
    bool found = false;
    for (int i=0; i<n; i++) {
        ll l = segments[i][0], r = segments[i][1], idx = segments[i][2];
        if (l > mx) {
            found = true; break;
        }

        mx = max(mx, r);
        ans[idx] = 1;
    }

    if (!found) {cout << -1 << "\n"; return;}

    for (auto &ele : ans) cout << (ele == 1 ? 1 : 2) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

