#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getPoints(vector<ll> shells, vector<vector<ll>> rounds) {
    ll ans = 0;
    for (auto round : rounds) {
        ll a = round[0];
        ll b = round[1];
        ll g = round[2];

        a--; b--; g--;

        swap(shells[a], shells[b]);
        if (shells[g] == 1) ans++;
    }
    return ans;
}

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> rounds;
    for (int i=0; i<n; i++) {
        ll a,b,g;
        cin >> a >> b >> g;
        rounds.push_back({a,b,g});
    }

    ll maxPoints = 0;

    vector<ll> shells = {1, 0, 0};
    maxPoints = max(maxPoints, getPoints(shells, rounds));

    shells = {0, 1, 0};
    maxPoints = max(maxPoints, getPoints(shells, rounds));

    shells = {0, 0, 1};
    maxPoints = max(maxPoints, getPoints(shells, rounds));

    cout << maxPoints << "\n";
}

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

