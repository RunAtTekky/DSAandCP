#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    ll mini = n;
    ll maxi = n * (n+1) / 2;

    if ( (m < mini) || (m > maxi) ) {
        cout << "-1\n"; return;
    }

    ll sum = 0;
    vector<ll> tree(n);

    for (ll i=n-1; i>=0; i--) {
        tree[i] = i+1;
        sum += i+1;
        ll req = sum + i - m;

        if (req == 0) {
            ll val = 1;
            for (ll j=i-1; j>=0; j--) {
                tree[j] = val++;
            }
            break;
        }
        if (req > 0) {
            req = i+1 - req;
            tree[i] = req;
            ll val = 1;
            for (ll j=i-1; j>=0; j--) {
                if (val == req) {
                    val++;
                }
                tree[j] = val++;
            }
            break;
        }
    }
    
    cout << n-1 << "\n";
    for (int i=n-1; i-1>=0; i--) {
        cout << tree[i] << " " << tree[i-1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
