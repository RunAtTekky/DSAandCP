#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n,m,p,q; cin >> n >> m >> p >> q;

    if (n % p == 0) {
        if ((n/p)*q == m) YES;
        else NO;
    } else YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
