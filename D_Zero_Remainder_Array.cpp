#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> rem;

    for (int i=0; i<n; i++) {
        ll a; cin >> a;
        if (a%k != 0) rem.push_back(k - (a%k));
    }

    if (rem.empty()) {cout << "0\n"; return;}

    map<ll,ll> freq;
    for (auto &ele : rem) freq[ele]++;

    pair<ll,ll> max_ele_fr = {0,0};

    for (auto &[ele, fr] : freq) {
        if (fr >= max_ele_fr.second) {
            max_ele_fr = {ele, fr};
        }
    }

    cout << (max_ele_fr.second-1) * (k) + max_ele_fr.first + 1 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
