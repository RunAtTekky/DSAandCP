#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353LL;
const int N = 5e5 + 5;

vector<ll> power;

void precomp() {
    power = vector<ll>(N);
    power[0] = 1;
    for (int i=1; i<N; i++) {
        power[i] = power[i-1] * 2 % MOD;
    }
}

ll get_sum(ll a, ll b) {
    return power[a] + power[b];
}

void solve() {
    ll n; cin >> n;

    vector<ll> p(n);
    for (auto &ele : p) cin >> ele;
    
    vector<ll> q(n);
    for (auto &ele : q) cin >> ele;

    ll p_max_idx = 0;
    ll q_max_idx = 0;

    vector<ll> ans;

    for (int i=0; i<n; i++) {
        if (p[i] > p[p_max_idx]) p_max_idx = i;
        if (q[i] > q[q_max_idx]) q_max_idx = i;

        ll ans = 0;

        if ( p[p_max_idx] > q[q_max_idx] || (p[p_max_idx] == q[q_max_idx] && q[i-p_max_idx] > p[i-q_max_idx]) ) ans = power[p[p_max_idx]] + power[q[i-p_max_idx]];
        else ans = power[q[q_max_idx]] + power[p[i-q_max_idx]];

        cout << ans % MOD << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomp();
    int t=1; cin >> t;
    while (t--) solve();
}
