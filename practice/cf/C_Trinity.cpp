#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    sort(arr.begin(), arr.end());

    int minimumSteps = INT_MAX;

    for (int i=0; i+1<n; i++) {
        int required_c = arr[i] + arr[i+1] - 1;
        int to_switch_ahead = n - (upper_bound(arr.begin(), arr.end(), required_c) - arr.begin());
        int to_switch_behind = i;

        minimumSteps = min(minimumSteps, to_switch_behind + to_switch_ahead);
    }

    cout << minimumSteps << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
