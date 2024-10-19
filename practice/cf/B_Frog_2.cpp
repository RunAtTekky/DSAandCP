#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> heights(n);
    for (auto &height : heights) cin >> height;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; (j<n && j<=i+k); j++) {
            int absDifference = abs(heights[i] - heights[j]);
            dp[j] = min(dp[j], dp[i] + absDifference);
        }
    }

    cout << dp[n-1] << "\n";
}

int main() {
    int t=1;
    while (t--) solve();
}
