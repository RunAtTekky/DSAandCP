#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<int> veca(n);
    for (auto &ele : veca) cin >> ele;
    
    vector<int> vecb(n);
    for (auto &ele : vecb) cin >> ele;
    
    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (veca[i] > vecb[i]) ans += veca[i] - vecb[i];
    }

    cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
