#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll checkMax(vector<pair<ll,ll>>& cows, ll i, ll j) {
    ll first = 0, second = 0, third = 0, fourth = 0;

    for (auto &[x,y] : cows) {
        if (x > i && y > j) {
            first++;
        } else if (x < i && y > j) {
            second++;
        } else if (x < i && y < j) {
            third++;
        } else if (x > i && y < j) {
            fourth++;
        }
    }

    return max({first, second, third, fourth});
}

void solve() {
    ll n, b; cin >> n >> b;

    vector<pair<ll,ll>> cows;

    set<ll> vFence;
    set<ll> hFence;
    for (int i=0; i<n; i++) {
        ll x, y; cin >> x >> y;

        cows.push_back({x,y});
        vFence.insert(x+1);
        hFence.insert(y+1);
    }

    ll ans = INT_MAX;
    for (auto v : vFence) {
        for (auto h : hFence) {
            ll first = 0, second = 0, third = 0, fourth = 0;
            for (auto &[x,y] : cows) {
                if (x > v && y > h) {
                    first++;
                } else if (x < v && y > h) {
                    second++;
                } else if (x < v && y < h) {
                    third++;
                } else if (x > v && y < h) {
                    fourth++;
                }
            }
            ans = min(ans, max({first, second, third, fourth}));
        }
    }

    cout << ans << "\n";
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

