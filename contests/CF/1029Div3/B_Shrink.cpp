#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> perm(n);

    int low = 1, high = n;

    // for (int i=0; i<n; i+=2) {
    //     perm[i] = low++;
    // }

    for (int i=1; i<n-1; i+=2) {
        perm[i] = high--;
    }
    for (int i=2; i<n-1; i+=2) {
        perm[i] = high--;
    }

    perm[0] = 1, perm[n-1] = 2;

    for (auto &ele : perm) cout << ele << " ";
    cout << "\n";
    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
