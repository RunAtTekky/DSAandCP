#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;

    vector<ll> horizontal(n);
    for (auto &ele : horizontal) cin >> ele;
    
    vector<ll> vertical(m);
    for (auto &ele : vertical) cin >> ele;

    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());

    // ll idx = lower_bound(horizontal.begin(), horizontal.end(), x) - horizontal.begin();
    // ll idx2 = lower_bound(vertical.begin(), vertical.end(), y) - vertical.begin();

    ll idx = 0;
    for (auto ele : horizontal) {
        if (ele < y) idx++;
        else break;
    }
    ll idx2 = 0;
    for (auto ele : vertical) {
        if (ele < x) idx2++;
        else break;
    }

    cout << idx + idx2 << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

