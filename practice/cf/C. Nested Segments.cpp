#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> segments;
    for (int i=0; i<n; i++) {
        ll l,r; cin >> l >> r;
        segments.push_back({l,r,i+1});
    }

    sort(segments.begin(), segments.end(), [&](auto &lft, auto &rgt) {
        if (lft[0] == rgt[0]) {
            return lft[1] > rgt[1];
        }

        return lft[0] < rgt[0];
    });

    pll limit_idx = {0,-1};

    for (int i=0; i<n; i++) {
        ll l = segments[i][0], r = segments[i][1], idx = segments[i][2];
        ll limit = limit_idx.first;
        if (limit < l) {
            limit_idx = {r,idx};
        } else {
            if (r <= limit) {
                cout << idx << " " << limit_idx.second << "\n"; return;
            } else {
                limit_idx = {r,idx};
            }
        }
    }

    cout << -1 << " " << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

