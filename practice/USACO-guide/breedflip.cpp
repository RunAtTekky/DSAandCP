#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    string original, arrived;
    cin >> original >> arrived;

    ll ans = 0;
    for (int i=0, j=0; i<n; i=j) {
        while (j<n && original[j] == arrived[j]) j++;
        if (j==n) break;
        while (j<n && original[j] != arrived[j]) j++;
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

