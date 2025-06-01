#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n; 
vector<ll> vec;
vector<vector<ll>> pref;

void prefix() {
    pref = vector<vector<ll>>(n+2, vector<ll>(40));
    for (int i=0; i<n; i++) {
        // bitset<32> val_bits(vec[i]);
        for (int bit=0; bit<32; bit++) {
            pref[i+1][bit] += pref[i][bit] + ((vec[i] >> bit) & 1);
            // cout << pref[i+1][bit] << " ";
        }
        // cout << "\n";
    }
}

bool ok(ll l, ll mid, ll k) {

    ll sum = 0;
    for (int bit=0; bit<32; bit++) {
        int bit_freq = pref[mid+1][bit] - pref[l][bit];

        if (bit_freq >= (mid-l+1)) sum += (1 << bit);
    }

    return sum >= k;
}

void f(ll l, ll k) {
    if (vec[l] < k) {cout << "-1 "; return;}

    ll start = l, end = n;
    while (start <= end) {
        ll mid = (start + end) / 2;

        if (ok(l, mid,k)) {
            start = mid + 1;
            // cout << mid << " correct\n";
        }
        else {
            end = mid - 1;
            // cout << mid << " wrong\n";
        }
    }

    cout << end + 1 << " "; 
}

void solve() {
    cin >> n;

    vec = vector<ll>(n);
    for (auto &ele : vec) cin >> ele;

    pref.clear();
    prefix();

    ll q; cin >> q;

    for (int query=0; query<q; query++) {
        ll l,k; cin >> l >> k;
        l--;

        f(l,k);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
