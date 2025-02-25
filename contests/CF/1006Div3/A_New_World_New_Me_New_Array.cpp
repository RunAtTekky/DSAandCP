#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k,p; cin >> n >> k >> p;

    int mini = abs(ceil(1.0 * abs(k)/p));

    if (mini > n) {cout << "-1\n";}
    else {cout << mini << "\n";}

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
