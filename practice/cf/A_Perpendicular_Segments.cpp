#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x,y,k; cin >> x >> y >> k;

    cout << "0 0 " << min(x,y) << " " << min(x,y) << "\n";
    cout << "0 " << min(x,y) << " " << min(x,y) << " 0\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
