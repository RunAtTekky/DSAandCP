#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> vec(2*n);
    for (auto &ele : vec) cin >> ele;

    map<ll,ll> freq;
    for (auto &ele : vec) freq[ele]++;

    ll odd = 0, equally_odd = 0, equally_even = 0;
    // vector<ll> cnt;
    for (auto &[val,fr] : freq) {
        // cout << val << " " << fr << "\n";
        // cnt.push_back(fr);
        if (fr&1) odd++;
        else if (fr%4 == 2) equally_odd++;
        else equally_even++;
    }

    // cout << odd << " " << equally_odd << " " << equally_even << "\n";

    ll ans = equally_odd * 2 + equally_even * 2 + odd;
    bool condition =  odd > 0 || (equally_even % 2 == 0);
    if (!condition) ans -= 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

