#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> apples(n);
    for (auto &apple : apples) cin >> apple;

    ll min_diff = LLONG_MAX;
    for (int mask=0; mask < (1<<n); mask++) {
        ll first = 0, second = 0;
        for (int i=0; i<n; i++) {
            if (mask & (1 << i)) {
                first += apples[i];
            } else {
                second += apples[i];
            }
        }
        ll diff = abs(first - second);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << "\n";

}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

