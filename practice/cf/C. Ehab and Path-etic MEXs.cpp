#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<pair<ll,ll>, ll> labels;
map<ll, vector<ll>> adj;

void solve() {
    ll n; cin >> n;

    ll target = -1;

    map<ll, pair<ll,ll>> ith_edge;
    map<ll,ll> indegree;
    for (int i=0; i<n-1; i++) {
        ll u,v; cin >> u >> v;

        if (u > v) swap(u,v);

        adj[u].push_back(v);
        adj[v].push_back(u);

        labels[{u,v}] = -1;

        indegree[u]++; indegree[v]++;
        if (indegree[u] >= 3) target = u; if (indegree[v] >= 3) target = v;

        ith_edge[i] = {u,v};
    }

    ll curr = 0;
    if (target != -1) {
        ll first = adj[target][0];
        ll second = adj[target][1];
        ll third = adj[target][2];

        labels[{min(target,first), max(target,first)}] = curr++;
        labels[{min(target,second), max(target,second)}] = curr++;
        labels[{min(target,third), max(target,third)}] = curr++;
    }

    for (auto &[edge, label] : labels) {
        if (label == -1) {
            label = curr++;
        }
    }

    for (int i=0; i<n-1; i++) {
        cout << labels[ith_edge[i]] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

