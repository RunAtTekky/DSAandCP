#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    map<ll,vector<ll>> color_x;
    map<ll,vector<ll>> color_y;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int color; cin >> color;

            color_x[color].push_back(i);
            color_y[color].push_back(j);
        }
    }

    ll ans = 0;

    for (auto &[color, val] : color_x) {
        sort(val.begin(), val.end());
        ll sz = val.size();
        ll prev = 0;
        for (int i=sz-2; i>=0; i--) {
            ll diff = val[i+1] - val[i];
            ll ahead = sz-1-i;

            prev += diff * ahead;

            ans += prev;
        }
    }

    for (auto &[color, val] : color_y) {
        sort(val.begin(), val.end());
        ll sz = val.size();
        ll prev = 0;
        for (int i=sz-2; i>=0; i--) {
            ll diff = val[i+1] - val[i];
            ll ahead = sz-1-i;

            prev += diff * ahead;

            ans += prev;
        }
    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
