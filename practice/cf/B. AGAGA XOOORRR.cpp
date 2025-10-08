#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    ll xor_val = 0;
    for (auto &ele : vec) xor_val ^= ele;

    if (xor_val == 0) {
        YES; return;
    }

    ll k = 0, count = 0;
    for (auto &ele : vec) {
        k ^= ele;
        if (k == xor_val) {
            k = 0; count++;
        }
    }

    if (count > 2) YES;
    else NO;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

