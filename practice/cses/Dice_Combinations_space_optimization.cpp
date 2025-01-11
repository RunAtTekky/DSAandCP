#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    vector<int> previous = {0,0,0,0,0,1};
    vector<int> current(6);

    // dp[i] = SUM(dp[i-k]), k=[1,6]
    for (int i=1; i<=n; i++) {
        long long sum = 0;
        
        for (int k=1; k<=5; k++) {
            current[k-1] = previous[k];
        }
        for (int k=0; k<6; k++) sum = (sum + previous[k]) % MOD;
        current[5] = sum;
        previous = current;
    }

    cout << current[5] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
