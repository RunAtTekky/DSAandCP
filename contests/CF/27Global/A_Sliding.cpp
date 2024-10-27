#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,m,r,c; cin >> n >> m >> r >> c;

    long long total = 0;

    total += (n-r)*m;
    total += (m-c);
    total += (m-1)*(n-r);

    cout << total << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
