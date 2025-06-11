// This is Jiangly's solution
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a;

    // Keeping track of empty spaces till that sheep
    int empty = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            empty++;
        } else {
            a.push_back(empty);
        }
    }

    // for (auto &ele : a) cout << ele << " ";
    // cout << "\n";
    
    // Find the middle sheep
    int mid = (a.size() - 1) / 2;
    long long ans = 0;
    for (auto x : a) {
        // Each time find out how many empty spaces are b/w mid sheep and curr sheep
        ans += abs(x - a[mid]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
