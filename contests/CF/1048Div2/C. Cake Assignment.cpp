#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {
    ll k, x; cin >> k >> x;

    ll a = (1LL)<<k;
    ll b = (1LL)<<k;

    ll reqA = x;
    ll reqB = a + b - x;

    vector<ll> path;

    while (a != reqA && b != reqB) {
        if (reqA < reqB) {
            ll tmp = reqA;
            reqA += tmp;
            reqB -= tmp;
            path.push_back(1);
        } else {
            ll tmp = reqB;
            reqB += tmp;
            reqA -= tmp;
            path.push_back(2);
        }
    }

    cout << path.size() << "\n";
    reverse(path.begin(), path.end());
    for (auto &ele : path) cout << ele << " ";
    cout << "\n";
    


}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}

