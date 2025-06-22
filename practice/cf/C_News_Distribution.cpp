#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// map<ll, vector<ll>> adj;
vector<set<ll>> adj;
map<ll,ll> present;
map<ll, vector<ll>> group_members;

map<ll,bool> visited;

set<ll> mutual_friends;

void dfs(ll curr) {
    if (visited[curr]) return;

    visited[curr] = true;

    for (auto members : group_members[curr]) mutual_friends.insert(members);
    
    for (auto nxt : adj[curr]) {
        dfs(nxt);
    }
}

void solve() {
    ll n, m; cin >> n >> m;

    adj = vector<set<ll>>(m);

    for (int i=0; i<m; i++) {
        ll num_members; cin >> num_members;
        vector<ll> members(num_members);

        set<ll> common;

        for (int j=0; j<num_members; j++) {
            cin >> members[j];

            if (present.count(members[j])) {
                common.insert(present[members[j]]);
            }
        }

        for (auto &group : common) {
            adj[group].insert(i);
            adj[i].insert(group);
        }

        for (auto &member : members) {
            present[member] = i;
        }

        group_members[i] = members;
    }

    vector<ll> ans(n+1);

    for (int i=0; i<m; i++) {
        mutual_friends.clear();
        dfs(i);

        for (auto &friends : mutual_friends) {
            ans[friends] = mutual_friends.size();
        }
    }

    for (int i=1; i<=n; i++) cout << max(1LL, ans[i]) << " ";
    cout << "\n";

    // for (auto &ele : ans) cout << ele << " ";
    // cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}