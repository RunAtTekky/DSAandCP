#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &e : a) cin >> e;

    int maxi = 0;

    map<int,int> freq;
    for (auto e : a) {
        freq[e]++;
        maxi = max(maxi, freq[e]);
    }

    cout << n - maxi << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
