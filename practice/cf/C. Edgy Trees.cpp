#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

map<ll, vector<pll>> adj;
map<ll, bool> visited;

const ll BLACK_EDGE = 1;
const ll RED_EDGE = 0;
const ll MOD = 1e9 + 7;

ll red_edge_group(ll curr) {
    if (visited[curr]) return 0;
    visited[curr] = true;

    ll total = 1;
    for (auto [nxt, edge] : adj[curr]) {
        if (edge == BLACK_EDGE) continue;
        total += red_edge_group(nxt);
    }

    return total;
}

void solve() {
    ll n, k; cin >> n >> k;

    for (int i=0; i<n-1; i++) {
        ll u,v,edge;
        cin >> u >> v >> edge;

        adj[u].push_back({v,edge});
        adj[v].push_back({u,edge});
    }

    auto pow = [](ll a, ll b) {
        int ans=1;
        while(b) {
            if(b&1)
                ans=(ans*a)%MOD;
            b/=2;
            a=(a*a)%MOD;
        }
        return ans;

        // ll ans = 1;
        // for (ll i=1; i<=b; i++) {
        //     ans = (ans % MOD) * (a % MOD) % MOD;
        // }
        // return (ans + MOD) % MOD;
    };

    ll total_seq = pow(n, k);
    ll bad_seq = 0;
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;

        ll nodes = red_edge_group(i);
        total_seq -= pow(nodes, k);
        total_seq = (total_seq + MOD) % MOD;
    }

    cout << (total_seq + MOD)%MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

