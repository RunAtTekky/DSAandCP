#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cansRequired; cin >> n >> cansRequired;

    vector<int> cansQty(n);
    for (auto &qty : cansQty) cin >> qty;

    sort(cansQty.begin(), cansQty.end());

    int buttonPresses = 0;
    for (int i=0; i<n; i++) {
        long long worstCaseCans = cansQty[i];

        int cans_atleast_worstcase = n - i;
        if (worstCaseCans * cans_atleast_worstcase >= cansRequired) {
            buttonPresses += cansRequired; break;
        }

        buttonPresses += worstCaseCans + 1;
        cansRequired -= worstCaseCans;
    }

    cout << buttonPresses << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
