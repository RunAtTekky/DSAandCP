#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    bool first = vec[0] == -1;
    bool last = vec[n-1] == -1;

    for (auto &ele : vec) {
        if (ele == -1) ele = 0;
    }

    if (first && last) {
        vec[0] = 0, vec[n-1] = 0;
        cout << 0 << "\n";
    } else if (first) {
        vec[0] = vec[n-1];
        cout << 0 << "\n";
    } else if (last) {
        vec[n-1] = vec[0];
        cout << 0 << "\n";
    } else {
        cout << abs(vec[0] - vec[n-1]) << "\n";
    }

    for (auto &ele : vec) cout << ele << " ";
    cout << "\n";

    // ll last = -1;
    // for (int i=0; i<n; i++) {
    //     if (vec[i] == -1) {
    //         vec[i] = 0; last = i;
    //     }
    // }
    //
    // ll sum = 0;
    // for (int i=0; i+1<n; i++) {
    //     ll diff = vec[i+1] - vec[i];
    //     sum += diff;
    // }
    //
    // if (sum == 0) {
    //     cout << 0 << "\n";
    //     for (auto &ele : vec) cout << ele << " ";
    //     cout << "\n"; return;
    // }
    //
    // if (last == 0 || last == n-1) {
    //     vec[last] = abs(sum);
    //     cout << 0 << "\n";
    // } else {
    //     cout << abs(sum) << "\n";
    // }
    //
    // for (auto &ele : vec) cout << ele << " ";
    // cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

