#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;

map<ll,vector<ll>> adj;
map<pl,ll> dp;

map<ll,bool> visited;

ll dfs(ll curr, ll prev, ll distance) {
    // cout << curr << " " << prev << "\n";
    if (adj[curr].size() == 1) {
        return (distance > 1) ? 1 : 0;
    }

    ll leaves = 0;
    for (auto &nxt : adj[curr]) {
        if (nxt == prev) continue;
        if (dp.count({curr,nxt})) {
            leaves += dp[{curr,nxt}];
        } else {
            leaves += dfs(nxt, curr, distance + 1);
        }
    }

    // cout << curr << " : " << leaves << "\n";

    return dp[{prev, curr}] = leaves;
}

void solve() {
    ll n; cin >> n;

    adj.clear(); dp.clear();
    for (int i=0; i<n-1; i++) {
        ll u,v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll mini = LLONG_MAX;
    for (int i=1; i<=n; i++) {
        if (adj[i].size() == 1) continue;
        mini = min(mini, dfs(i, -1, 0));
        // cout << "ans" << " -> " << mini << "\n";
    }

    cout << ((mini == LLONG_MAX) ? 0 : mini) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
