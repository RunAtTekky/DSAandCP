#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, total_money; cin >> n >> total_money;

    vector<pair<int,int>> books(n);

    for (int i=0; i<n; i++) { cin >> books[i].first; }
    for (int i=0; i<n; i++) { cin >> books[i].second; }

    sort(books.begin(), books.end(), [&](auto x, auto y) {
        return x.first < y.first;
    });

    vector<vector<int>> dp(n+1, vector<int>(total_money+1));
    // 2D dp (1e3, 1e5)

    // if (curr_money >= money[i])
    // dp[i][curr_money] = money[i] + dp[i-1][curr_money - money[i]]
    // else dp[i][curr_money] = dp[i-1][curr_money]

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=total_money; j++) {
            
            if (j >= books[i-1].first) {
                dp[i][j] = books[i-1].second + dp[i-1][j - books[i-1].first];
            } 
            dp[i][j] = max(dp[i][j],dp[i-1][j]);

            // cout << dp[i][j] << "\t\n"[j==total_money];
        }
    }

    cout << dp[n][total_money] << "\n";


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
