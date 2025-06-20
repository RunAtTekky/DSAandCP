#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> ans;

void precomp() {
    ans[0] = 0;
    for (int i=1; i<64; i++) {
        ans[i] = ans[i-1] * 2 + i;
    }
}

string get_bin(ll n) {
    string res = "";
    while (n > 0) {
        res += (n&1) ? "1" : "0";
        n = n>>1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;

    string bin_s = get_bin(n);

    // cout << bin_s << "\n";

    ll res = 0;
    int m = bin_s.size();
    for (int i=0; i<m; i++) {
        if (bin_s[i] == '1') {
            // if (i == 0) {
            //     res += 1; continue;
            // }
            res += ans[i] + i + 1;
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    precomp();
    while (t--) solve();
}
