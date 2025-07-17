#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    vector<ll> towers(n);
    for (auto &ele : towers) cin >> ele;

    ll current_tower_height = towers[k-1];

    vector<ll> larger_towers;
    for (auto tower : towers) {
        if (tower >= current_tower_height) {
            larger_towers.push_back(tower);
        }
    }

    sort(larger_towers.begin(), larger_towers.end());

    ll water_level = 0;
    for (int i=0; i+1<larger_towers.size(); i++) {
        ll diff = larger_towers[i+1] - larger_towers[i];

        if ( diff > (larger_towers[i] - water_level) ) {NO; return;}

        water_level += diff;
    }

    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
