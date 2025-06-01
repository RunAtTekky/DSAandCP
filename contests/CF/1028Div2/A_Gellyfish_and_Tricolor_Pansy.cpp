#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c,d; cin >> a >> b >> c >> d;

    if (min(a,c) >= min(b,d)) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
