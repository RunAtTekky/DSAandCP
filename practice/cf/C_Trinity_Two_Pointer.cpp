#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    sort(arr.begin(), arr.end());

    int minimumSteps = INT_MAX;

    for (int i=0, j=0; i+1<n; i++) {
        while (j<n && arr[i] + arr[i+1] > arr[j]) j++;

        minimumSteps = min(minimumSteps, n - j + i);
    }

    cout << minimumSteps << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
