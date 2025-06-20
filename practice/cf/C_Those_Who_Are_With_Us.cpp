#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    int maxi = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            maxi = max(maxi, grid[i][j]);
        }
    }

    vector<int> rows;
    vector<int> cols;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == maxi) {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
