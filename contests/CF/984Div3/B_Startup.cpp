#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> bottle_cost(k+1);

    int brand, cost; 
    for (int i=0; i<k; i++) {
        cin >> brand >> cost;

        bottle_cost[brand] += cost;
    }

    sort(bottle_cost.begin(), bottle_cost.end());
    reverse(bottle_cost.begin(), bottle_cost.end());

    long long total = 0;
    for (int i=0; i<min(n,k+1); i++) {
        total += bottle_cost[i];
    }

    cout << total << "\n";
}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
