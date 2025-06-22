#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if ((b1 == b2 + b3) && (l2 == l3)) {
        if (l1 + l2 == b1) {
            YES; return;
        }
    }

    if ((l1 == l2 + l3) && (b2 == b3)) {
        if (b1 + b2 == l1) {
            YES; return;
        }
    }

    if ( (l1 == l2) && (l2 == l3) ) {
        if ((b1+b2+b3) == l1) {
            YES; return;
        }
    }

    if ( (b1 == b2) && (b2 == b3) ) {
        if ((l1+l2+l3) == b1) {
            YES; return;
        }
    }

    NO;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
