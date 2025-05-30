#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    if (k >= 3) {cout << "0\n"; return;}

    vector<ll> vals;
    for (auto &ele : vec) vals.push_back(ele);

    sort(vals.begin(), vals.end());

    ll mini = vals.front();
    // cout << mini << "\n";

    if (k == 1) {
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ll diff = abs(vec[i] - vec[j]);
                mini = min(mini, diff);
                // cout << mini << "\n";
            }
        }
        cout << mini << "\n"; return;
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {

            ll nxt = abs(vec[i] - vec[j]);

            // Check if this nxt value is closest to some
            ll idx = lower_bound(vals.begin(), vals.end(), nxt) - vals.begin();

            ll diff1 = LLONG_MAX, diff2 = LLONG_MAX;

            if (idx < n) diff1 = abs(vals[idx] - nxt);
            if (idx - 1 >= 0) diff2 = abs(vals[idx-1] - nxt);

            ll best_diff = min(diff1, diff2);

            mini = min({mini, best_diff, nxt});
        }
    }

    cout << mini << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
