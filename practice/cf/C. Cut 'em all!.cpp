#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,vector<ll>> adj;
map<ll,bool> visited;

ll ans = 0;

ll dfs(ll curr) {
    if (visited[curr]) return 0;
    visited[curr] = true;

    ll nodes = 1;

    for (auto nxt : adj[curr]) {
        if (visited[nxt]) continue;

        ll nodes_below = dfs(nxt);
        if (nodes_below % 2 == 0) ans++;
        else nodes += nodes_below;
    }

    return nodes;
}

void solve() {
    ll n; cin >> n;

    for (int i=0; i<n-1; i++) {
        ll u,v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n&1) {
        cout << -1 << "\n"; return;
    }

    dfs(1);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

