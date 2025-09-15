#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> timings;
    for (int i=0; i<n; i++) {
        ll arrive, leave; cin >> arrive >> leave;

        timings.push_back({arrive, 1});
        timings.push_back({leave, -1});
    }

    sort(timings.begin(), timings.end());

    ll curr = 0;
    ll ans = 0;
    for (auto &[arrive, point] : timings) {
        curr += point;
        ans = max(ans, curr);
    }

    cout << ans << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

