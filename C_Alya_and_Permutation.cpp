#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);

    int maximum_value = 0;

    cout << maximum_value << "\n";

    for (auto ele : perm) cout << ele << " ";
    cout << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
