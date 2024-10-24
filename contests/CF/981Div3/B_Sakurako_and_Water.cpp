#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    map<int,int> useInDiagonal;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] >= 0) continue;
            int diff = j-i;
            useInDiagonal[diff] = max(useInDiagonal[diff], abs(matrix[i][j]));
        }
    }
    int total_use_of_magic = 0;
    for (auto [diagonalDifference, magicFreq] : useInDiagonal) total_use_of_magic += magicFreq;

    cout << total_use_of_magic << "\n";


}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
