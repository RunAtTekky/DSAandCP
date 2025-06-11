#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a, b, k; cin >> a >> b >> k;

    vector<int> boys(k);
    for (auto &ele : boys) cin >> ele;

    vector<int> girls(k);
    for (auto &ele : girls) cin >> ele;

    map<ll, vector<ll>> boy_adj;
    for (int i=0; i<k; i++) {
        boy_adj[boys[i]].push_back(girls[i]);
    }
    map<ll, vector<ll>> girl_adj;
    for (int i=0; i<k; i++) {
        girl_adj[girls[i]].push_back(boys[i]);
    }

    ll ans = 0;
    for (auto &[node, edges] : boy_adj) {
        for (auto &edge : edges) {
            ans += k - (girl_adj[edge].size() + boy_adj[node].size() - 1);
        }
    }
    cout << ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
