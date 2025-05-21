#include <bits/stdc++.h>
using namespace std;

// Right, Down, Left, Up
vector<pair<int,int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0}};

void spiral(int row, int col, int dir_idx, int stepsize, int val, vector<vector<int>>& grid) {
    if (val >= (grid.size() * grid.size())) return;

    // We only go two directions with one stepsize
    for (int i=0; i<2; i++) {
        for (int i=0; i<stepsize; i++) {
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid.size()) {
                grid[row][col] = val++;
            }
            row += dir[dir_idx].first;
            col += dir[dir_idx].second;
        }
        dir_idx = (dir_idx + 1) % 4;
    }

    spiral(row, col, dir_idx, stepsize+1, val, grid);
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    int row = ceil(n/2.0) - 1, col = ceil(n/2.0) - 1;

    spiral(row, col, 0, 1, 0, grid);

    for (auto &grid_row : grid) {
        for (auto &ele : grid_row) cout << ele << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
