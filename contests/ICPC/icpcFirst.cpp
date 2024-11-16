#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;

    vector<long long> cost(n);
    for (auto &e : cost) cin >> e;

    sort(cost.begin(), cost.end());

    vector<long long> pickLastK(n);

    long long sum = 0;
    for (int i=0; i<n; i++) {
        sum += cost[i];
        if ((i - k) >= 0) sum -= cost[i-k];

        pickLastK[i] = sum;
    }

    // for (auto e : pickLastK) cout << e << " ";
    // cout << "\n";

    vector<long long> res(n);

    for (int m=0; m<n; m++) {
        long long ans;
        if (m-k-1 >= 0) {
            ans = pickLastK[m] + res[m-k-1];
        }
        else ans = pickLastK[m];

        res[m] = ans;

        cout << ans << " ";

    }
    

    cout << "\n";


}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
