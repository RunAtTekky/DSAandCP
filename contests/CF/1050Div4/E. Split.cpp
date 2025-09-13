#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    if (n % k != 0) {
        cout << 0 << "\n"; return;
    }

    map<ll,ll> freq;
    for (int i=0; i<n; i++) {
        freq[vec[i]]++;
    }

    for (auto &[key, fr] : freq) {
        if (fr % k != 0) {
            cout << 0 << "\n"; return;
        }
    }

    map<ll, queue<ll>> mp;
    ll threshold = 0;

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll val = vec[i];

        if (mp[val].size() == (freq[val] / k)) {
            ll lst = mp[val].front();
            mp[val].pop();
            mp[val].push(i+1);
            threshold = max(threshold, lst);
        } else {
            mp[val].push(i+1);
        }

        ans += i + 1 - threshold;
    }

    cout << ans << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

