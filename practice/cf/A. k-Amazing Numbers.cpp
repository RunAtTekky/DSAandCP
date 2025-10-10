#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    

    map<ll, vector<ll>> indexes;
    for (int i=1; i<=n; i++) indexes[i].push_back(0);
    for (int i=0; i<n; i++) {
        indexes[vec[i]].push_back(i+1);
    }
    for (int i=1; i<=n; i++) indexes[i].push_back(n+1);

    ll mini = INT_MAX, upper_limit = n;
    vector<ll> ans(n+1, -1);
    for (const auto &[val, idxs] : indexes) {
        ll maxDiff = 0;
        for (int i=0; i+1<idxs.size(); i++) {
            ll diff = idxs[i+1] - idxs[i];
            maxDiff = max(maxDiff, diff);
        }

        if (maxDiff == 0) continue;

        if (maxDiff < mini) {
            for (int i=maxDiff; i<=upper_limit; i++) ans[i] = val;
            mini = maxDiff;
            upper_limit = maxDiff-1;
        }
    }

    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

