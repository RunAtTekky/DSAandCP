#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> vecs;
    for (int i=0; i<n; i++) {
        ll k; cin >> k;

        vector<ll> vec(k);
        for (int j=0; j<k; j++) {
            cin >> vec[j];
        }
        vecs.push_back(vec);
    }

    sort(vecs.begin(), vecs.end());

    while (vecs.size() != 0) {
        ll sz = vecs[0].size();

        for (auto &ele : vecs[0]) cout << ele << " ";

        vector<vector<ll>> new_vecs;
        for (int i=1; i<vecs.size(); i++) {
            if (vecs[i].size() > sz) {
                vector<ll> new_vec = vector<ll>(vecs[i].begin() + sz, vecs[i].end());
                new_vecs.push_back(new_vec);
            }
        }

        vecs = new_vecs;
    }

    cout << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

