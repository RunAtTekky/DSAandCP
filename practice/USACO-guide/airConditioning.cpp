#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll n, m;
vector<ll> required_cooling;
vector<vector<ll>> airConditioners;

ll check(ll mask, vector<vector<ll>>& airConditioners) {

    vector<ll> turnedONac;
    for (int i=0; i<m; i++) {
        if (mask & (1<<i)) {
            turnedONac.push_back(i);
        }
    }

    vector<ll> effective_cooling(101);
    ll total_money = 0;
    for (auto &idx : turnedONac) {
        ll start = airConditioners[idx][0]; ll end = airConditioners[idx][1];
        ll cooling = airConditioners[idx][2]; ll money = airConditioners[idx][3];

        total_money += money;
        for (int i=start; i<=end; i++) {
            effective_cooling[i] += cooling;
        }
    }

    // for (auto &ele : effective_cooling) cout << ele << " ";
    // cout << "\n";
    

    // for (auto &ele : turnedONac) cout << ele << " ";
    // cout << " -> ";

    for (int i=0; i<=100; i++) {
        if (required_cooling[i] > effective_cooling[i]) {
            total_money = INT_MAX; break;
        }
    }

    // cout << total_money << "\n";

    return total_money;
}

void solve() {
    cin >> n >> m;

    required_cooling = vector<ll>(101);
    for (int i=0; i<n; i++) {
        ll s, t, c; cin >> s >> t >> c;
        for (int j=s; j<=t; j++) required_cooling[j] += c;
    }

    // for (auto &ele : required_cooling) cout << ele << " ";
    // cout << "\n";
    

    airConditioners.clear();
    for (int i=0; i<m; i++) {
        ll a, b, p, m;
        cin >> a >> b >> p >> m;

        airConditioners.push_back({a, b, p, m});
    }

    ll min_money = INT_MAX;
    for (int mask=0; mask < (1<<m); mask++) {
        ll money = check(mask, airConditioners);
        min_money = min(min_money, money);
    }

    cout << min_money << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

