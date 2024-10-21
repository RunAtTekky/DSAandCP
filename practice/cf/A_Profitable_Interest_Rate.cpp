#include <bits/stdc++.h>
using namespace std;

void solve() {
    int aliceCoins, minimumDeposit;
    cin >> aliceCoins >> minimumDeposit;

    if (aliceCoins >= minimumDeposit) {
        cout << aliceCoins << "\n"; return;
    }

    int difference = minimumDeposit - aliceCoins;

    int depositingCoins = aliceCoins - difference;

    cout << ((depositingCoins>0) ? depositingCoins : 0) << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
