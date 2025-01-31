#include <bits/stdc++.h>
using namespace std;

#define YES cout << "TAK\n"
#define NO cout << "NIE\n"  

void solve() {
    int n,m; cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m+1));

    for (int i=0; i<n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> matrix[i][j];
        }
    }

    // dp[i][x] = {
    //      is possible to make x from first i rows,
    //      choice
    //}
    vector<vector<pair<bool,int>>> dp(n+1, vector<pair<bool,int>>(1024));

    for (int j=1; j<=m; j++) {
        dp[0][matrix[0][j]].first = true;
        dp[0][matrix[0][j]].second = j;
    }

    // dp[i][x] = (dp[i-1][ x ^ matrix[i][j] ]) ? true : false;
    for (int i=1; i<n; i++) {

        for (int x=0; x<=1023; x++) {
            for (int j=1; j<=m; j++) {
                dp[i][x].first = (dp[i-1][x^matrix[i][j]].first) ? true : false;
                if (dp[i][x].first) {
                    dp[i][x].second = j;
                    break;
                }
            }
        }
    }

    int value_made = -1;
    for (int i=1; i<=1023; i++) {
        if (dp[n-1][i].first) {
            YES;
            value_made = i;
            break;
        }
    }

    if (value_made == -1) {NO; return;}

    int curr = n-1;
    vector<int> answers;
    while (curr>=0) {
        int choice = dp[curr][value_made].second;
        answers.push_back(choice);

        value_made ^= matrix[curr][choice];
        curr--;
    }

    reverse(answers.begin(), answers.end());
    for (auto &ele : answers) cout << ele << " ";
    cout << "\n";



}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
