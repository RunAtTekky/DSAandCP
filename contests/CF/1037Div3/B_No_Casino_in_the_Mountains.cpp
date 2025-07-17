#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    vector<int> rains(n);
    for (auto &ele : rains) cin >> ele;
    
    ll days = 0, hikes = 0;
    for (int i=0; i<n; i++) {
        if (rains[i] == 0) days++;
        else {
            days = 0;
            continue;
        }
        if (days == k) {
            days = 0;
            i++;
            hikes++;
        }
    }

    cout << hikes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
