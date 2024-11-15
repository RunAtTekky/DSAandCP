#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    // If even, no problemo
    if (!(n&1)) {
        for (int i=1; i<=n/2; i++) {
            cout << i << " " << i << " ";
        }
        cout << "\n"; return;
    }

    if (n < 27) {cout << "-1\n"; return;}

    vector<int> buns(n+1);
    buns[1] = 1;
    buns[10] = 1;
    buns[23] = 4;
    buns[26] = 1;
    buns[27] = 4;

    int x = 5;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (buns[i] == 1 || buns[i] == 4) continue;

        buns[i] = x;
        cnt++;

        if (cnt == 2) {x++; cnt=0;}
    }

    for (int i=1; i<=n; i++) {
        cout << buns[i] << " ";
    }
    cout << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
