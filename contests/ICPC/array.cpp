#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;

    vector<vector<int>> not_minimum(n);

    for (int i=0; i<k; i++) {
        int l,r,m; cin >> l >> r >> m;

        l--; r--;

        for (int idx=l; idx<=r; idx++) {
            not_minimum[idx].push_back(m);
        }
    }

    vector<int> answer(n);

    for (int i=0; i<n; i++) {
        auto to_not_insert = not_minimum[i];

        int sz = to_not_insert.size();

        if (sz >= n) {cout << "-1\n"; return;}

        sort(to_not_insert.begin(), to_not_insert.end());

        int to_insert = 1;
        int j=0;
        while (j<sz && to_not_insert[j] == to_insert) {
            j++;
            to_insert++;
        }

        answer[i] = to_insert;
    }

    for (auto &ele : answer) cout << ele << " ";
    cout << "\n";
    
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
