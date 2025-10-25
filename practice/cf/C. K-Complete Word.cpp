#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    ll ans = 0;
    for (int i=0; i<(k+1)/2; i++) {
        map<ll,ll> freq;
        ll maxi = 0;
        ll cnt = 0;
        for (int j=i; j<n; j+=k) {
            freq[s[j]]++;
            maxi = max(maxi, freq[s[j]]);

            ll rev = k - (j%k + 1);
            rev = (j/k)*k + rev;

            cnt++;
            if (j==rev) continue;
            cnt++;
            freq[s[rev]]++;
            maxi = max(maxi, freq[s[rev]]);
        }

        // cout << i << " " << maxi << "\n";
        // cout << i << " " << cnt << " " << maxi << "\n";
        ans += cnt - maxi;
    }

    cout << ans << "\n";
    // cout << "\n";

    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

