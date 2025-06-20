#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> diff(n);
    for (int i=0; i<n; i++) {
        diff[i] = vec[i] - i;
    }

    ll maxi = 0;
    map<ll,ll> sum;
    for (int i=0; i<n; i++) {
        sum[diff[i]] += vec[i];
        maxi = max(maxi, sum[diff[i]]);
    }

    cout << maxi << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; 
    while (t--) solve();
}
