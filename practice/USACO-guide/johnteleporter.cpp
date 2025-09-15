#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    if (c > b || d < a) {
        cout << b - a << "\n";
    } else {
        cout << min(abs(a-c), abs(a-d)) + min(abs(b-c), abs(b-d)) << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

