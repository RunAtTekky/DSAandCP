#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_jump(ll jump, vector<pair<ll,ll>>& segments) {
    ll min_pos = 0, max_pos = 0;

    for (auto &segment : segments) {
        min_pos = max(segment.first, min_pos - jump);
        max_pos = min(segment.second, max_pos + jump);

        if (min_pos > max_pos) return false;
    }
    // cout << jump << " can jump\n";
    return true;
}

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> segments(n);

    for (auto &segment : segments) cin >> segment.first >> segment.second;

    ll start = 0, end = 1e9;

    while (start <= end) {
        ll max_jump = (start + end) / 2;

        if (can_jump(max_jump, segments)) {
            end = max_jump - 1;
        } else {
            start = max_jump + 1;
        }
    }

    cout << start << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
