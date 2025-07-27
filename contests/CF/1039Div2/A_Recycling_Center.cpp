#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e11;

void solve() {
    ll n; cin >> n;
    ll c; cin >> c;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    ll ans = 0;
    for (int i=0; i<n; i++) {
        sort(vec.begin(), vec.end());

        ll idx = -1;
        for (int j=0; j<n; j++) {
            if ((vec[j] <= c) && (vec[j] < INF)) idx = j;
        }

        if (idx == -1) {
            ans += 1;
        } else {
            vec[idx] = INF;
        }

        for (int k=0; k<n; k++) {
            if (vec[k] < INF) vec[k] = vec[k] * 2;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
