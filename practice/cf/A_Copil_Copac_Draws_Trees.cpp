#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vpi;

map<int, vpi> adj;
map<int,int> parent_idx;
map<int,int> dp;
map<pair<int,int>,int> index_of;

map<int, bool> visited;

void dfs(int curr) {
    for (auto [node, idx] : adj[curr]) {
        if (dp[node] != 0) continue;

        dp[node] = dp[curr] + (idx <= parent_idx[curr]);
        parent_idx[node] = idx;

        dfs(node);
    }
}

void solve() {
    int n; cin >> n;

    adj.clear();
    parent_idx.clear();
    dp.clear();

    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;

        if (u > v) swap(u,v);

        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    dp[1] = 1;
    parent_idx[1] = -1;

    dfs(1);

    int ans = 0;
    for (auto &[node,steps] : dp) ans = max(ans, steps);

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
