#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (int i=0; i<n; i+=2) {
        vec[i] = -1;
    }
    for (int i=1; i<n; i+=2) {
        vec[i] = 3;
    }

    if (n%2 == 0) vec[n-1] = 2;

    for (auto &ele : vec) cout << ele << " ";
    cout << "\n";
    

    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
