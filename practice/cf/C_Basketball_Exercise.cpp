#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> vec2(n);
    for (auto &ele : vec2) cin >> ele;

    ll up = vec.back(), down = vec2.back();
    for (int i=n-2; i>=0; i--) {
        ll tmp = max(up, vec[i] + down);
        down = max(down, vec2[i] + up);
        up = tmp;
    }

    cout << max(up, down) << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; 
    while (t--) solve();
}
