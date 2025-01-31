#include <bits/stdc++.h>
using namespace std;

long long get_sum(vector<long long>& pref, int start, int end) {
    return pref[start+1] - pref[end];
}

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    // Solve for 1, 2, 3 and so on...
    // dp[i][j] => maximum score possible with subarray vec[i..j]
    /*
        dp[i][j] = max(
            vec[i] + sum[i+1..j] - dp[i+1][j],
            vec[j] + sum[i..j-1] - dp[i][j-1]
        )
    */

    vector<long long> pref(n+1);
    for (int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + vec[i-1];
    }
    for (auto &ele : pref) cout << ele << " ";
    cout << "\n";
    
    

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int sz=1; sz<=n; sz++) {
        for (int initial=0; initial+sz<=n; initial++) {
            // Now dp[initial..initial+sz] = dp[initial]
            int i = initial, j=initial+sz-1;
            if (i==j) {
                dp[i][j] = vec[i];
                continue;
            }
            if (i==0 && j==2) {
                cout << dp[i+1][j] << " ";
                cout << dp[i][j-1] << " ";
            }
            dp[i][j] = max(
                vec[i] + get_sum(pref, i+1, j) - dp[i+1][j],
                vec[j] + get_sum(pref, i,j-1) - dp[i][j-1]
            );
        }
    }

    // for (auto &vec : dp) {
    //     for (auto &ele : vec) {
    //         cout << ele << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         cout << i << " " << j << " : ";
    //         cout << dp[i][j] << "\n";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    


    // Final subproblem
    cout << dp[0][n-1] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
