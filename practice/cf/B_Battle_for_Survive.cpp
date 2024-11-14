#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &e : a) cin >> e;

    long long toNegate = 0;

    for (int i=0; i+2<n; i++) {
        toNegate += a[i];
    }

    long long maximumLast = a[n-1] - (a[n-2] - toNegate);

    cout << maximumLast << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
