#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    vector<ll> s_set(n);
    for (auto &ele : s_set) cin >> ele;
    
    vector<ll> t_set(n);
    for (auto &ele : t_set) cin >> ele;

    map<ll,ll> cnt;
    map<ll,ll> same;

    for (int i=0; i<n; i++) {
        s_set[i] = s_set[i] % k;
        ll a = s_set[i] % k;
        ll b = abs(a-k);

        if (a != b) {
            cnt[a]++; cnt[b]++;
            same[a] = b; same[b] = a;
        } else {
            cnt[a]++;
        }

    }

    for (int i=0; i<n; i++) {
        ll req = t_set[i] % k;

        if (cnt[req] == 0) {NO; return;}

        cnt[req]--;
        if (same.count(req)) {
            cnt[same[req]]--;
        }
    }

    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
