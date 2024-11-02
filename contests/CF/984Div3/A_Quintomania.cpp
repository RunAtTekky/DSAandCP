#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> tones(n);
    for (auto &tone : tones) cin >> tone;

    for (int i=0; i+1<n; i++) {
        int diff = abs(tones[i] - tones[i+1]);
        if (diff == 5 || diff == 7) continue;
        else {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
