#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (n==1 && k==1) {cout << "1\n1\n"; return;}

    if (k==1 || k==n) {cout << "-1\n"; return;}

    cout << "3\n";
    if (k&1) {

    cout << "1 " << k-1 << " " << k+2 << "\n";
    }

    else {
        cout << "1 " << k << " " << k+1 << "\n";
    }


}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
