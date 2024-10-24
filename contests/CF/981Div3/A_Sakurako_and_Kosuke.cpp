#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    int x=0;

    bool sakurakoTurn = true;

    int curr = 1;

    while (abs(x) <= n) {
        if (sakurakoTurn) {
            x -= curr;
        }
        else {
            x += curr;
        }

        sakurakoTurn = !sakurakoTurn;
        curr += 2;
    }

    if (sakurakoTurn) {
        cout << "Kosuke\n";
    }
    else {
        cout << "Sakurako\n";
    }

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
