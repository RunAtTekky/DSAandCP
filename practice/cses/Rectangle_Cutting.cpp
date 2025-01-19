#include <bits/stdc++.h>
using namespace std;

// dp[a][b] => cuts required to make rectangle (axb) into squares
int dp[501][501];

#define debug(x) cerr << #x << ' ' << x << '\n';

void precomp() {
    dp[0][0] = 0;
    memset(dp, 1e4, sizeof dp);

    // All rectangles (axa) will need 0 cuts
    for (int i=1; i<=500; i++) {
        dp[i][i] = 0;
    }

    for (int i=1; i<=500; i++) {
        for (int j=1; j<=500; j++) {
            if (i==j) continue;
            if (dp[i][j] <= 1) continue;

            int a = i;
            for (int b=1; b<j; b++) {
                dp[i][j] = min(dp[i][j], 1 + dp[a][b] + dp[a][j-b]);
                if (dp[i][j] <= 1) break;
            }

            int b = j;
            for (a=1; a<i; a++) {
                dp[i][j] = min(dp[i][j], 1 + dp[b][a] + dp[b][i-a]);
                if (dp[i][j] <= 1) break;
            }

            dp[j][i] = dp[i][j];
        }
    }
}

void solve() {
    int length, breadth; cin >> length >> breadth;

    cout << dp[length][breadth] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomp();
    solve();
}
