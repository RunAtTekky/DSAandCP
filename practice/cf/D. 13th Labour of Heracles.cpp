#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, vector<ll>> adj;

void solve() {
    ll n; cin >> n;

    adj.clear();

    map<ll,ll> weights;
    for (int i=1; i<=n; i++) {
        ll w; cin >> w;
        weights[i] = w;
    }

    for (int i=1; i<n; i++) {
        ll u,v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<ll,ll>> vals;
    for (int i=1; i<=n; i++) {
        if (adj[i].size() >= 2) {
            vals.push_back({weights[i], adj[i].size()-1});
        }
    }

    sort(vals.begin(), vals.end(), greater<pair<ll,ll>>());

    // for (auto &[val,fr] : vals) cout << val << " " << fr << "\n";
    // cout << "\n";
    ll base = 0;
    for (int i=1; i<=n; i++) base += weights[i];

    cout << base << " ";

    ll x = 1, i=0, prev = 0;
    while (x + 1 < n && i<vals.size()) {
        ll val = vals[i].first;
        ll fr = vals[i].second;

        cout << base + (x-prev)*val << " ";

        if (fr == x - prev) {
            base += val * fr;
            prev += fr;
            i++;
        }
        x++;
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

