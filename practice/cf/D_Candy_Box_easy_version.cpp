#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    map<ll,ll> freq;
    for (auto &ele : vec) freq[ele]++;

    map<ll, vector<ll>> candies;
    for (auto &[key, val] : freq) {
        candies[val].push_back(key);
    }

    vector<bool> can(n+1);

    ll ans = 0;
    for (auto &[key, val] : candies) {
        ll sz = val.size();
        for (ll curr = key; curr > 0; curr--) {
            if (can[curr] == false) {
                can[curr] = true;
                sz--;
            }
            if (sz == 0) break;
        }
    }

    for (ll i=0; i<n+1; i++) {
        ans += (can[i]) ? i : 0;
    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
