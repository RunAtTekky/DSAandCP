#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> tree_height(n);
    for (auto &height : tree_height) cin >> height;
    
    vector<int> max_height_reachable(n);
    max_height_reachable[n-1] = *max_element(tree_height.begin(), tree_height.end());

    vector<int> max_behind(n);
    vector<int> min_ahead(n);

    int maxi = 0, mini = n;

    for (int i=0; i<n; i++) {
        maxi = max(maxi, tree_height[i]);
        max_behind[i] = maxi;

        min_ahead[n-1-i] = mini;
        mini = min(mini, tree_height[n-1-i]);
    }

    for (int i=n-1; i>=0; i--) {
        if (max_behind[i] > min_ahead[i]) {
            max_height_reachable[i] = max_height_reachable[i+1];
        }
        else max_height_reachable[i] = max_behind[i];
    }

    for (auto &maxi : max_height_reachable) cout << maxi << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
