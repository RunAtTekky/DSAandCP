#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n,a,b; cin >> n >> a >> b;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> distanceAhead(n+1);

    for (int i=n-2; i>=0; i--) {
        ll diff = vec[i+1] - vec[i];
        ll kingdomAhead = n - 1 - i;

        distanceAhead[i] = diff * kingdomAhead + distanceAhead[i+1];
    }

    ll mini = LLONG_MAX;
    for (int i=0; i<n; i++) {
        ll conquerKingdomAhead = distanceAhead[i] * b;
        ll reachTillHere = (a + b) * vec[i];
        ll res = conquerKingdomAhead + reachTillHere;
        // cout << i << " " << res << "\n";
        mini = min(mini, res);

    }

    ll distAll = distanceAhead[0] + vec[0]*n;
    ll ifAll = distAll * b;
    mini = min(mini, ifAll);

    // cout << distAll << " " << ifAll << "\n";
    //
    cout << mini << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

