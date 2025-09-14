#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, x; cin >> n >> x;

    vector<int> weights(n);
    for (auto &weight : weights) cin >> weight;
    
    sort(weights.begin(), weights.end());

    ll total = 0;
    for (int i=0, j=n-1; i<=j; j--) {
        ll sum = weights[i] + weights[j];
        if (i == j) sum -= weights[i];

        if (sum <= x) i++;

        total++;
    }

    cout << total << "\n";


}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

