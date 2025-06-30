#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> teas(n);
    for (auto &ele : teas) cin >> ele;
    
    vector<ll> capacity(n);
    for (auto &ele : capacity) cin >> ele;

    vector<ll> pref;
    pref.push_back(0);

    for (auto &ele : capacity) {
        pref.push_back(pref.back() + ele);
    }

    // Delta Encoding
    vector<ll> delta(n+1);
    vector<ll> ans(n+1);

    for (int i=0; i<n; i++) {
        ll target = teas[i] + pref[i];

        ll idx = upper_bound(pref.begin(), pref.end(), target) - pref.begin() - 1;
        
        delta[i] += 1;
        delta[idx] -= 1;

        ans[idx] += target - pref[idx];
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] + capacity[i]*delta[i] << " ";
        delta[i+1] += delta[i];
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
