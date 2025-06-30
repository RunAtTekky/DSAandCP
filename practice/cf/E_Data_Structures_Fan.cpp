#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    string bin; cin >> bin;

    vector<ll> pref(n+1);
    
    for (int i=0; i<n; i++) {
        pref[i+1] = pref[i] ^ vec[i];
    }

    ll x_0 = 0, x_1 = 0;
    for (int i=0; i<n; i++) {
        if (bin[i] == '1') {
            x_1 ^= vec[i];
        } else {
            x_0 ^= vec[i];
        }
    }

    ll query; cin >> query;
    while (query--) {
        ll choice; cin >> choice;

        if (choice == 1) {
            // Update
            ll l,r; cin >> l >> r;
            l--; r--;

            ll change = pref[r+1] ^ pref[l];
            
            x_0 ^= change;
            x_1 ^= change;
        } else {
            ll type; cin >> type;

            if (type == 0) cout << x_0 << " ";
            if (type == 1) cout << x_1 << " ";
        }
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
