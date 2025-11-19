#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec_a(n);
    for (auto &ele : vec_a) cin >> ele;

    ll gcd_all = vec_a[0];
    for (const auto &ele : vec_a) gcd_all = gcd(gcd_all, ele);
    if (gcd_all != 1) { cout << -1 << "\n"; return; }

    ll curr_gcd = vec_a[0], mini = INT_MAX;
    for (int idx=1; idx<n; idx++) {
        curr_gcd = gcd(curr_gcd, vec_a[idx]);
        if (curr_gcd != 1) continue;

        ll backtrack_gcd = vec_a[idx];
        for (int j=idx-1; j>=0; j--) {
            backtrack_gcd = gcd(backtrack_gcd, vec_a[j]);
            if (backtrack_gcd == 1) {
                ll oper = idx - j + n-1;
                mini = min(mini, oper);
                break;
            }
        }
    }

    ll ones = count(vec_a.begin(), vec_a.end(), 1);
    if (ones == n) {cout << 0 << "\n"; return;}

    cout << mini - ones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

