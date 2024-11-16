#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> trees(n);
    for (auto &tree : trees) cin >> tree;

    int tallest_tree_index = max_element(trees.begin(), trees.end()) - trees.begin();

    vector<int> max_possible_position(n);
    max_possible_position[tallest_tree_index] = trees[tallest_tree_index];

    // Find the minimum tree ahead
    int minimum_tree_ahead = *min_element(trees.begin() + tallest_tree_index + 1, trees.end());

    // Turn all the trees ahead of it to this
    fill(trees.begin() + tallest_tree_index, trees.end(), trees[tallest_tree_index]);


    int current_index = tallest_tree_index-1;
    int previous_index = tallest_tree_index;

    for (; current_index>=0; current_index--) {
        if (trees[current_index] <= minimum_tree_ahead) {
            continue;
        }

        for (int i=current_index+1; i<previous_index; i++) {

            
        }
        
    }


}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
