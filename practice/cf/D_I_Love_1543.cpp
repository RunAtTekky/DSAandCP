#include <bits/stdc++.h>
using namespace std;

void solve() {
    int row, col; cin >> row >> col;

    vector<string> grid(row);
    for (int i=0; i<row; i++) cin >> grid[i];

    int total = 0;

    for (int layer=0; layer<min(row,col)/2; layer++) {
        string this_layer = "";

        // Top side
        for (int i=layer; i<col-layer; i++) this_layer += grid[layer][i];

        // Right side
        for (int i=layer+1; i<row-layer-1; i++) this_layer += grid[i][col-layer-1];

        // Bottom side
        for (int i=col-layer-1; i>layer; i--) this_layer += grid[row-layer-1][i];

        // Left side
        for (int i=row-layer-1; i>=layer+1; i--) this_layer += grid[i][layer];

        // Because this layer is cyclic
        this_layer += this_layer;

        for (int i=0; i<this_layer.size()/2; i++) {
            total += (this_layer.substr(i,4) == "1543");
        }


    }

    cout << total << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
