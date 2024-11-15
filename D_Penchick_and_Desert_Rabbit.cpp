#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> trees(n);
    for (auto &tree : trees) cin >> tree;

    int tallest_tree_index = max_element(trees.begin(), trees.end()) - trees.begin();

    cout << tallest_tree_index << "\n";


}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
