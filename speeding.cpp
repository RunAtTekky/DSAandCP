#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> speedLimit;
    for (int i=0; i<n; i++) {
        ll length, limit;
        cin >> length >> limit;

        while (length--) speedLimit.push_back(limit);
    }

    vector<ll> bessieSpeed;
    for (int i=0; i<m; i++) {
        ll length, speed;
        cin >> length >> speed;

        while (length--) bessieSpeed.push_back(speed);
    }

    ll maxSpeedOverLimit = 0;
    for (int i=0; i<100; i++) {
        maxSpeedOverLimit = max(maxSpeedOverLimit, bessieSpeed[i] - speedLimit[i]);
    }

    cout << maxSpeedOverLimit << "\n";
}

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

