#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    sort(arr.begin(), arr.end());

    int start = 0, end = n;

    cout << end << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
