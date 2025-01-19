#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    

    vector<vector<long long>> dp(n, vector<long long>(m+1));

    // dp[i][j] => ways to make different arrays till i'th index when
    // current index value is j

    // Base case
    // If first element is 0, then dp[0][1..m] = 1 else dp[0][j] = 1

    if (vec[0] == 0) {
        for (int j=1; j<=m; j++) dp[0][j] = 1;
    }
    else dp[0][vec[0]] = 1;

    for (int i=1; i<n; i++) {

        // We can choose any value
        if (vec[i] == 0) {
            for (int j=1; j<=m; j++) {
                if (j - 1 >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }

                if (j + 1 <= m) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }

                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }

        // Value already available
        else {
            if (vec[i]-1 >= 1) {
                dp[i][vec[i]] += dp[i-1][vec[i]-1];
                dp[i][vec[i]] %= MOD;
            }

            if (vec[i] + 1 <= m) {
                dp[i][vec[i]] += dp[i-1][vec[i]+1];
                dp[i][vec[i]] %= MOD;
            }

            dp[i][vec[i]] += dp[i-1][vec[i]];
            dp[i][vec[i]] %= MOD;
        }
    }

    long long answer = 0;
    for (auto ways : dp[n-1]) {
        answer += ways;
        answer %= MOD;
    }

    cout << answer << "\n";


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
