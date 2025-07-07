#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll n; cin >> n;

    ll j,k; cin >> j >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    int maxi = *max_element(vec.begin(), vec.end());

    if (maxi == vec[j-1]) {
        YES; return;
    }

    else if (k == 1) {
        NO;
    } else {
        YES;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
