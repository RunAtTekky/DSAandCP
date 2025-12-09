#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const char SPLITTER = '^';

void take_input(vector<string>& grid) {
    string line;
    while (cin >> line) grid.push_back(line);
}

void print_grid(vector<string>& grid) {
    for (auto &line : grid) cout << line << "\n";
    cout << "\n";
}

ll count_splits(vector<string>& grid) {
    ll no_of_splits = 0;
    ll s_idx = find(grid[0].begin(), grid[0].end(), 'S') - grid[0].begin();

    set<ll> current_beams = {s_idx};
    for (int row = 1; row < grid.size(); row++) {
        set<ll> new_beams;
        for (auto &idx : current_beams) {
            if (grid[row][idx] == SPLITTER) {
                no_of_splits++;
                if (idx-1 >= 0) new_beams.insert(idx-1);
                if (idx+1 < grid[row].size()) new_beams.insert(idx+1);
            } else {
                new_beams.insert(idx);
            }
        }
        current_beams = new_beams;
        // for (auto &ele : current_beams) cout << ele << " ";
        // cout << "\n";
        
    }

    return no_of_splits;
}

void solve() {
    vector<string> grid;
    take_input(grid);

    // print_grid(grid);
    ll splits = count_splits(grid);
    cout << splits << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

