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

    // dp[row][col] => {val,idx}
    vector<vector<vector<pair<int,int>>>> dp(n+1, vector<vector<pair<int,int>>>(m+1));

    for (int col=1; col<=m; col++) {
        pair<int,int> pr = {matrix[n-1][col],col};
        dp[n-1][col].push_back(pr);
    }

    int idx = -1;
    bool found = false;
    for (int row=n-2; row>=0; row--) {
        for (int col=1; col<=m; col++) {

            set<int> st;
            for (int below=1; below<=m; below++) {

                for (auto pr: dp[row+1][below]) {
                    // keep track of all the possibilities have been filled
                    int new_val = pr.first ^ matrix[row][col];
                    pair<int,int> new_pr = {new_val, below};

                    int sz = st.size();
                    st.insert(new_val);

                    if (sz != st.size()) {
                        dp[row][col].push_back(new_pr);

                        // If on starting row and positive value is found
                        if (row == 0 && new_val > 0) {
                            idx = below;
                            found = true;
                            YES;
                            cout << col << " ";
                            break;
                        }

                    }
                    if (st.size() == 1024) break;
                }
                if (st.size() == 1024) break;
                if (found) break;
            }
            if (found) break;
        }
        if (found) break;
    }

    // Edge case, when there is only one row
    if (n == 1) {
        for (int i=1; i<=m; i++) {
            if (matrix[0][i] != 0) {
                YES;
                cout << i << " ";
                return;
            }
        }
    }

    if (!found) {
        NO; return;
    }

    int curr = 1;

    while (curr < n) {
        auto vec_pr = dp[curr][idx];

        cout << idx << " ";

        for (auto pr : vec_pr) {
            if (pr.first > 0) {
                idx = pr.second;
            }
        }
        curr++;
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
