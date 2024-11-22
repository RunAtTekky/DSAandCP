#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c; cin >> a >> b >> c;

    int only_a = (abs(b-c)&1) ? 0 : 1;
    int only_b = (abs(a-c)&1) ? 0 : 1;
    int only_c = (abs(b-a)&1) ? 0 : 1;

    cout << only_a << " " << only_b << " " << only_c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
