#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; cin >> k;

    vector<int> vec(k);
    for (auto &ele : vec) cin >> ele;
    
    int sz = vec.size() - 2;

    if (sz == 1) {
        cout << "1 1\n"; return;
    }

    sort(vec.begin(), vec.end());

    for (auto n : vec) {
        if (sz%n == 0) {
            int m = sz/n;
            if (binary_search(vec.begin(), vec.end(), m)) {
                cout << n << " " << sz/n << "\n";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
