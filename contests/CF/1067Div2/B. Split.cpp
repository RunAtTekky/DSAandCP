#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(2*n);
    for (auto &ele : vec) cin >> ele;

    map<ll,ll> freq;
    for (auto &ele : vec) freq[ele]++;

    ll ans = 0;
    vector<ll> cnt;
    for (const auto &[val,fr] : freq) cnt.push_back({fr});

    ll lft_side = 0, rgt_side = 0;
    for (int i=0; i+1<cnt.size(); i++) {
        ll fr = cnt[i];

        if (fr&1) {
            if (lft_side > rgt_side) {
                lft_side += fr/2;
                rgt_side += fr/2 + 1;
            } else {
                lft_side += fr/2 + 1;
                rgt_side += fr/2;
            }
            ans++;
        } else {
            if ((fr/2) & 1) {
                lft_side += fr/2;
                rgt_side += fr/2;
                ans += 2;
            } else {
                if (lft_side > rgt_side) {
                    lft_side += fr/2 - 1;
                    rgt_side += fr/2 + 1;
                } else {
                    lft_side += fr/2 + 1;
                    rgt_side += fr/2 - 1;
                }
                ans += 2;
            }
        }
    }

    ll remaining_lft = n - lft_side;
    ll remaining_rgt = n - rgt_side;
    ans += (remaining_lft&1);
    ans += (remaining_rgt&1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

