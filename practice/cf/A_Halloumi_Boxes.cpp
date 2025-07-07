#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

typedef long long ll;

void solve() {
    ll n,k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    if (k > 1) {
        YES; return;
    }

    if (is_sorted(vec.begin(), vec.end())) {
        YES;
    } else {
        NO;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
