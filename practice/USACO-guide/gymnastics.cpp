#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;

bool check(vector<vector<ll>> results, ll i, ll j) {
    bool iAhead = false;
    bool jAhead = false;
    for (auto &ranks : results) {
        for (int k=0; k<ranks.size(); k++) {
            if (ranks[k] == i) {
                iAhead = true; break;
            } else if (ranks[k] == j) {
                jAhead = true; break;
            }
        }

        if (iAhead && jAhead) return false;
    }

    return true;
}

void solve() {
    ll k, n; cin >> k >> n;

    vector<vector<ll>> results;
    for (int i=0; i<k; i++) {
        vector<ll> ranks(n);
        for (int j=0; j<n; j++) {
            cin >> ranks[j];
        }
        results.push_back(ranks);
    }

    ll ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            bool isConsistent = check(results, i, j);
            if (isConsistent) ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

