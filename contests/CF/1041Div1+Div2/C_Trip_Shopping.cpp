#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;

void solve() {
    ll n, rounds; cin >> n >> rounds;

    vector<ll> a(n);
    for (auto &ele : a) cin >> ele;
    
    vector<ll> b(n);
    for (auto &ele : b) cin >> ele;
    
    vector<pl> vec(n);
    for (int i=0; i<n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        vec[i] = {a[i],b[i]};
    }

    sort(vec.begin(), vec.end(), [&](auto x, auto y) {
        int sum_l = x.first + x.second;
        int sum_r = y.first + y.second;

        return sum_l < sum_r;
    });

    ll min_diff = LLONG_MAX;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll curr_diff = abs(vec[j].second - vec[j].first) + abs(vec[i].second - vec[i].first);
            vector<ll> v = {vec[i].first, vec[i].second, vec[j].first, vec[j].second};
            sort(v.begin(), v.end());

            ll best_diff = v[3] - v[0] + v[2] - v[1];
            min_diff = min(min_diff, best_diff - curr_diff);

            break;
        }
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += b[i] - a[i];
    }

    cout << ans + min_diff << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
