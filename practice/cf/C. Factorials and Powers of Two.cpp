#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> factorials;
vector<ll> powers;
const ll N = 1e12+1;

void setFactorials() {
    ll curr = 2;
    for (ll i = 3; curr < N; i++) {
        curr *= i;

        factorials.push_back(curr);
    }
}

void setPowerOf2() {
    ll curr = 1;
    powers.push_back(curr);
    for (ll i = 1; curr < N; i++) {
        curr *= 2;

        powers.push_back(curr);
    }
}

void precomp() {
    setFactorials();
    setPowerOf2();
}

void solve() {
    ll n; cin >> n;

    ll m = factorials.size();
    ll ans = __builtin_popcountll(n);
    for (ll mask=0; mask<(1<<m); mask++) {
        // bitset<16> bits(mask);
        // cout << bits << "\n";
        ll sum = 0, factorials_used = 0;
        for (ll i=0; i<m; i++) {
            bool ith_bit_on = mask & (1<<i);
            if (ith_bit_on) {
                // cout << i << " " << "ON ";
                sum += factorials[i];
                factorials_used++;
            }
        }
        // cout << "\n";
        //
        // cout << sum << "\n";

        if (sum > n) continue;
        ll required = n - sum;

        ll steps = factorials_used + __builtin_popcountll(required);
        // cout << steps << "\n";
        // cout << mask << " " << steps << "\n";
        // if (steps == 0) {
        //     cout << mask << " " << sum << " " << steps << "\n";
        // }

        ans = min(ans, steps);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomp();
    int t=1; cin >> t;
    while (t--) solve();
}
