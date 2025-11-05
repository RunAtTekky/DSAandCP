#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, vector<ll>> adj;
priority_queue<ll, vector<ll>, greater<ll>> pq;
map<ll,bool> visited;
vector<ll> ans;

void dfs(ll curr) {
    ans.push_back(curr);
    visited[curr] = true;

    for (auto nxt : adj[curr]) {
        if (!visited[nxt]) pq.push(nxt);
        visited[nxt] = true;
    }

    if (pq.empty()) return;

    ll to_visit = pq.top();
    pq.pop();
    dfs(to_visit);
}

void solve() {
    ll n, m; cin >> n >> m;

    for (int i=0; i<m; i++) {
        ll u,v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (auto &ele : ans) cout << ele << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

