#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    int mini = *min_element(vec.begin(), vec.end());
    int maxi = *max_element(vec.begin(), vec.end());

    sort(vec.begin(), vec.end());

    // if ((maxi-mini) % 2 == 0) {
    //     cout << "0\n"; return;
    // }
    int lft = 0, rgt = 0;

    for (int i=0; i<n; i++) {
        if ((maxi - vec[i]) % 2 == 0) {
            // cout << i << "\n"; return;
            lft = i; break;
        }
    }
    for (int i=n-1; i>=0; i--) {
        if ((vec[i] - mini) % 2 == 0) {
            // cout << n-1-i << "\n"; return;
            rgt = n-1-i; break;
        }
    }

    cout << min(lft, rgt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
