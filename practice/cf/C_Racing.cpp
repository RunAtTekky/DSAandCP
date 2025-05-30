#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> can_change;

    ll low_level = 0;
    vector<ll> L(n);
    vector<ll> R(n);

    for (int i=0; i<n; i++) cin >> L[i] >> R[i];

    for (int i=0; i<n; i++) {
        // cout << "\nPass " << i << "\n";
        ll l = L[i], r = R[i];

        if (vec[i] == -1) {
            can_change.push_back(i);
        } else {
            low_level += vec[i];
        }

        // If we need to increase to reach l
        while (low_level < l) {
            if (can_change.empty()) {
                cout << "-1\n"; return;
            }
            low_level++;
            // cout << low_level << "\n";
            vec[can_change.back()] = 1;
            can_change.pop_back();
            // cout << can_change.size() << "\n";
        }

        // If we want to stay at our level to avoid hitting r
        while (low_level + can_change.size() > r) {
            if (can_change.empty()) {
                cout << "-1\n"; return;
            }
            vec[can_change.back()] = 0;
            can_change.pop_back();
        }
    }

    for (auto &ele : vec) cout << max(0LL, ele) << " ";
    cout << "\n";
    
    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
