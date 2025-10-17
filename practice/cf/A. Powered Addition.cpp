#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(ll req) {
    ll i = 0;
    while (req) {
        req >>= 1;
        i++;
    }
    return i;
}

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    ll prev = INT_MIN, ans = 0;
    for (int i=0; i<n; i++) {
        ll req = prev - vec[i];
        req = max(0LL, req);

        ll max_x_req = check(req);
        ans = max(ans, max_x_req);

        prev = max(prev, vec[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

