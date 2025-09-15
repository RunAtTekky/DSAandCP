#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a <= c && c <= b) {
        cout << d - a << "\n";
    } else if (a <= d && d <= b) {
        cout << b - c << "\n";
    } else if (d < a || b < c) {
        cout << b - a + d - c << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

