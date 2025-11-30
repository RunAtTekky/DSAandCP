#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> get_divisors(ll n) {
    set<ll> divisors;
    for (int i=1; i*i<=n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    return divisors;
}

bool valid_through_all_jumps(vector<ll>& vec, int jump) {
    int n = vec.size();
    ll gcdd = 0;
    for (int j = 0; j + jump < n; j++) {
        ll diff = abs(vec[j] - vec[j + jump]);
        gcdd = gcd(gcdd, diff);
    }
    return gcdd != 1;
}

void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    auto divisors = get_divisors(n);

    ll ans = 0;
    for (const auto &divisor : divisors) {
        bool is_valid = valid_through_all_jumps(vec, divisor);
        ans += is_valid;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

